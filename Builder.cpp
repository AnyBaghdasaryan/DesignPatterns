#include <iostream>
#include <string>

class ProcessorType
{
    public:
        std::string processor;
};

class Sensor
{
    public:
        float Msensor;
};


class Camera
{
    public:
        ProcessorType*  processorType;
        Sensor* sensor;
    
        void specifications()
        {
            std::cout << "Sensor: " << sensor->Msensor << " megapixel "<< std::endl;
            std::cout << "Processor Type: " << processorType->processor << std::endl;
        }
};

class Builder
{
    public:
        virtual ProcessorType* getProcessorType() = 0;
        virtual Sensor* getSensor() = 0;
};

class Director
{
    Builder* builder;

    public:
        void setBuilder(Builder* newBuilder)
        {
            builder = newBuilder;
        }

        Camera* getCamera()
        {
            Camera* camera = new Camera();

            camera->sensor = builder->getSensor();

            camera->processorType = builder->getProcessorType();

            return camera;
        }
};

class CanonBuilder : public Builder
{
    public:
        ProcessorType* getProcessorType()
        {
            ProcessorType* processorType = new ProcessorType();
            processorType->processor = "DIGIC 8 ";
            return processorType;
        }

        Sensor* getSensor()
        {
            Sensor* sensor = new Sensor();
            sensor->Msensor = 24.1;
            return sensor;
        }
};

class NikonZ7Builder : public Builder
{
    public:


        ProcessorType* getProcessorType()
        {
            ProcessorType* processorType = new ProcessorType();
            processorType->processor = "EXPEED 6";
            return processorType;
        }

        Sensor* getSensor()
        {
            Sensor* sensor = new Sensor();
            sensor->Msensor = 45.7;
            return sensor;
        }
};


int main()
{
    Camera* camera; 
    Director director;

    CanonBuilder canonBuilder;
    NikonZ7Builder nikonZ7Builder;

    std::cout << "  Canon EOS 250D:" << std::endl;
    director.setBuilder(&canonBuilder); 
    camera = director.getCamera();
    camera->specifications();

    std::cout << std::endl;

    std::cout << "  Nikon Z7: " << std::endl;
    director.setBuilder(&nikonZ7Builder); 
    camera = director.getCamera();
    camera->specifications();

    return 0;
}

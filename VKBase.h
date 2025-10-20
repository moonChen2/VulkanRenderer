#pragma once

#include "EasyVKStart.h"

namespace vulkan{
    //singleton
    class GraphicsBase{
    private:
        GraphicsBase() = default;
        GraphicsBase(GraphicsBase&&) = delete;
        ~GraphicsBase(){}

        VkInstance instance;
        std::vector<const char*> instanceLayers;
        std::vector<const char*> instanceExtensions;

        //Debug
        VkDebugUtilsMessengerEXT debugMessenger;
        VkResult CreateDebugMessenger(){
            //TODO
        }

        //window surface
        VkSurfaceKHR surface;

        static void AddLayerOrExtension(std::vector<const char*>& container, const char* name){
            for(auto& i : container){
                //already exist
                if(!strcmp(name, i)){
                    return;
                }
            }

            container.emplace_back(name);
        }


    public:
        //init when first used
        static GraphicsBase& GetSingleton(){
            static GraphicsBase singleton = GraphicsBase();
            return singleton;
        }
        //Getter
        VkInstance Instance() const {
            return instance;
        }
        const std::vector<const char*>& InstanceLayers() const {
            return instanceLayers;
        }
        const std::vector<const char*>& InstanceExtensions() const {
            return instanceExtensions;
        }

        void AddInstanceLayer(const char* layerName){
            AddLayerOrExtension(instanceLayers, layerName);
        }
        void AddInstanceExtensions(const char* extensionName){
            AddLayerOrExtension(instanceExtensions, extensionName);
        }

        VkResult CreateInstance(VkInstanceCreateFlags flags = 0){
            //TODO
        }
        VkResult CheckInstanceLayers(std::span<const char*> layersToCheck){
            //TODO
        }

        void SetInstanceLayers(const std::vector<const char*>& layerNames){
            instanceLayers = layerNames;
        }

        VkResult CheckInstanceExtensions(std::span<const char*> extensionsToCheck,
                                         const char* layerName = nullptr) const{
            //TODO
        }
        void SetInstanceExtensions(const std::vector<const char*>& extensionsNames){
            instanceExtensions = extensionsNames;
        }

        VkSurfaceKHR GetSurface() const{
            return surface;
        }

        void SetSurface(VkSurfaceKHR surface){
            if(!this->surface){
                this->surface = surface;
            }
        }
    };

}
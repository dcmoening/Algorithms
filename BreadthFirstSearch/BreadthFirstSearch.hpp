#pragma once
#include <iostream>
#include <list>

#include "node.hpp"

namespace algorithm
{
    
    struct BreadthFirstSearch
    {
        template<typename T>
        static inline Node<T>* Search(const Node<T>& node, const T& key)
        {
            std::list<const Node<T>*> nodes;
            Node<T>* result = nullptr;
            nodes.push_back(&node);
            for(auto it = nodes.begin(); it != nodes.end(); ++it)
            {
                for(const auto& child : ((*it)->GetChildren()))
                {
                    nodes.push_back(child);
                    if(key == child->GetData())
                    {
                        result = child;
                    }
                }
            }

            // display the order of the items in nodes demonstrating the 
            // breadth first algorithm
            for(auto node : nodes)
            {
                std::cout << node->GetData() << std::endl;
            }        

            return result;    
        }
    };
}

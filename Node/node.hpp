#pragma once

#include <memory>
#include <vector>

/*
 * Tree will consist of a parent node and children nodes. A child can only have
 * one parent, but a parent may have multiple children. When a node is deleted
 * its children become the children of the parent of the deleted parent. Root
 * node may not be deleted if it has multiple children. If root node only has
 * one child and the root node is deleted, the child node is now the root node.
 */
namespace algorithm
{
    template<typename T>
    struct Node
    {
        inline Node() : _parentNode(nullptr) {}
        inline explicit Node(const T& data) : _parentNode(nullptr), _data(data) {}
       
        inline ~Node()
        {
            if(_parentNode != nullptr)
            {
                // Transfer children to parent
                for(auto& node : _childrenNodes)
                {
                    //parentNode->AddChild(node);    
                }
            }
        }        
        
        Node(const Node&) = delete;
        Node& operator=(Node&) = delete;        

        void  AddChild(
            std::unique_ptr<Node<T>>& node)
        {
            node->SetParent(this);
            _childrenNodes.push_back(node.get());
        }
        
        inline void SetParent(Node<T>* node)
        {
            _parentNode = node;
        }
        
        inline const T& GetData() const
        {
            return _data;
        }

        inline void SetData(const T& data)
        {
            _data = data;
        }
        
        inline const auto& GetChildren() const
        {
            return _childrenNodes;
        }

        private:
            Node<T>* _parentNode;
            std::vector<Node<T>*> _childrenNodes;
            T _data;
    };
}

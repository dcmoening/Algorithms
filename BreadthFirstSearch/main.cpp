#include <memory>

#include "node.hpp"
#include "BreadthFirstSearch.hpp"

using namespace algorithm;

int main ()
{
    auto rootNode = std::make_unique<Node<int>>(1);
    auto node2 = std::make_unique<Node<int>>(2); 
    rootNode->AddChild(node2);
    auto node3 = std::make_unique<Node<int>>(3);
    node2->AddChild(node3);
    auto node4 = std::make_unique<Node<int>>(4);
    rootNode->AddChild(node4);
    auto node5 = std::make_unique<Node<int>>(5);
    node4->AddChild(node5);
    auto node6 = std::make_unique<Node<int>>(6);
    node2->AddChild(node6);
    
    /*      1
     *    2   4
     *   3 6   5
     *
     */

    auto foundNode = BreadthFirstSearch::Search<int>(*rootNode, 4);

    if(foundNode != nullptr)
    {
        std::cout << "found node: " << foundNode->GetData() << std::endl;
    }
    else
    {
        std::cout << "node not found" << std::endl;
    }

    return 0;    
}

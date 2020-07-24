#include "graphedge.h"
#include "graphnode.h"
using std::unique_ptr;
using std::move;

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

  //delete _chatBot; // original, Task 5, _chatBot is not a pointer

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)         // original
void GraphNode::AddEdgeToChildNode(unique_ptr<GraphEdge> edge) // my code : Task 4
{
//_childEdges.push_back(edge);       // original
  _childEdges.push_back(move(edge)); // my code : Task 4
  // when push_back, the copy of data is created. unique_ptr cannot be copied.
  
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // _chatBot = chatbot;             // original
    // _chatBot->SetCurrentNode(this); // original
    _chatBot = move(chatbot);  // my code , Task-5
    _chatBot.SetCurrentNode(this);  // my code , Task-5    
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
  //newNode->MoveChatbotHere(_chatBot); // original
    newNode->MoveChatbotHere(move(_chatBot)); // my code , Task 5
    // _chatBot = nullptr; // invalidate pointer at source // original, Task 5
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

  //return _childEdges[index];       // original
    return _childEdges[index].get(); // my code

    ////
    //// EOF STUDENT CODE
}
#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"

#include <memory>
using std::vector;
using std::unique_ptr;

// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE : Task 4
    ////

    // data handles (owned) ==> modify to unique_ptr
  //vector<GraphEdge *> _childEdges;  // edges to subsequent nodes
    vector<unique_ptr<GraphEdge>> _childEdges; // my code

    // data handles (not owned)
    vector<GraphEdge *> _parentEdges; // edges to preceding nodes 

  //ChatBot *_chatBot; // original, Task 5
    ChatBot  _chatBot; // my code, _chatBot is saved in stack memory.

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
  //void AddEdgeToChildNode(GraphEdge *edge);             // original
    void AddEdgeToChildNode(unique_ptr<GraphEdge> edge);  // my code : Task 4

    //// STUDENT CODE
    ////

  //void MoveChatbotHere(ChatBot* chatbot); // original
    void MoveChatbotHere(ChatBot chatbot);  // my code, Task 5

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */
#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation

    // Rule of Five : 1 (destructor)
    ~ChatBot();

    //// STUDENT CODE : Task 2
    ////

    // Rule of Five : 2 (assignment operator)
    // The default assignment operation performs a shallow copy.
    // If a deep copy is needed, it has be implemented by the programmer.
    ChatBot &operator=(const ChatBot &source);
    
    // Rule of Five : 3 (copy contructor)
    // The default copy constructor performs a shallow copy.
    // If something else is needed, the programmer has to implement it.
    ChatBot(const ChatBot &source);

    // Rule of Five : 4 (move contructor)
    // Copying objects can be an expensive operation.
    // The move constructor transfers the ownership of a resource from a rvalue object to a lvalue object.
    ChatBot(ChatBot &&source);

    // Rule of Five : 5 (move assignment operator)
    // With this operator, ownership of a resource can be transferred from one object to another.
    // The internal behavior is very similar to the move constructor.
    ChatBot &operator=(ChatBot && source);

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
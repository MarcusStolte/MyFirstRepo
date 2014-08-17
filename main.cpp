#include <iostream>
#include <string>

using namespace std;

class cDate{
public:
    void printName(){
        cout << dateName << endl;
    }
    
    void printDate(){
        cout << sDay << "/" << sMonth << "/" << sYear << endl;
    }
    
    short sDay, sMonth, sYear;
    string dateName;
};

class cNode{
public:
    cNode();
    void setDate(cDate date);
    cDate* getDate();
    void setNext(cNode node);
    void setNextNull();
    cNode* getNext();
    void setPrev(cNode node);
    void setPrevNull();
    cNode* getPrev();
private:
    cDate *pDate; //Points to a date
    cNode *pNext; //Points to next Node
    cNode *pPrev; //Points to previous Node
};

cNode *pStart = nullptr; //Points to first Node
cNode *pTemp = nullptr; //Points to a temp Node
cNode *pIter = nullptr; //Iterates over Nodes
cDate *pDate = nullptr;

cNode::cNode(){
    pDate = nullptr;
    pNext = nullptr;
    pPrev = nullptr;
}

void cNode::setDate(cDate date){
    pDate = &date;
}

cDate* cNode::getDate(){
    return pDate;
}

void cNode::setNext(cNode node){
    pNext = &node;
}

void cNode::setNextNull(){
    pNext = nullptr;
}

cNode* cNode::getNext(){
    return pNext;
}

void cNode::setPrev(cNode node){
    pPrev = &node;
}

void cNode::setPrevNull(){
    pPrev = nullptr;
}

cNode* cNode::getPrev(){
    return pPrev;
}

void printNodes(){
    int iCounter = 1;
    
    if(pStart == nullptr){
        cout << "The Doubly Linked List is empty." << endl << endl;
    }else{
        pIter = pStart;
        while(pIter->getNext() != nullptr){
            
            cout << iCounter << ". Exam - ";
            pIter->getDate()->printName();
            cout << " is due on: ";
            pIter->getDate()->printDate();
            cout << endl;
            
            pIter = pIter->getNext();
            iCounter++;
        }
        
        cout << iCounter << ". Exam - ";
        pIter->getDate()->printName();
        cout << " is due on: ";
        pIter->getDate()->printDate();
        cout << endl;
    }
}

void addNode(){
    pTemp = new cNode;
    
    pDate = new cDate;
    
    cout << "Enter Exam name: ";
    cin >> pDate->dateName;
    cout << "Enter day due: ";
    cin >> pDate->sDay;
    cout << "Enter month due: ";
    cin >> pDate->sMonth;
    cout << "Enter year due: ";
    cin >> pDate->sYear;
    cout << endl;
    
    pTemp->setDate(*pDate);
    
    
    
    //First Node
    if(pStart == nullptr){
        pStart = pTemp;
        
    //Not First Node
    }else{
        pIter = pStart;
        
        while(pIter->getNext() != nullptr){
            pIter = pIter->getNext();
        }
        
        pIter->setNext(*pTemp);
        pTemp->setPrev(*pIter);
        pTemp->setNextNull();
    }
    
    
}

int main(){
    bool running = true;
    
    cout << "Exam Date Database by Marcus Stolte." << endl;
    cout << "Written on the 17th of August, 2014." << endl << endl;
    
    while(running){
        cout << "Select an option below: " << endl;
        cout << "1. Print List" << endl;
        cout << "2. Add Entry" << endl;
        cout << "3. Remove Entry" << endl;
        cout << "4. Save List" << endl;
        cout << "~. Exit Application" << endl;
        cout << ":: ";
    
        int iInput;
        cin >> iInput;
    
        switch(iInput){
            case 1:
                printNodes();
                break;
            case 2:
                addNode();
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                running = false;
                break;
        }
    }
    
    return 0;
}
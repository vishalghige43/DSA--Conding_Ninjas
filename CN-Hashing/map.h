#include<string>
#include<iostream>
using namespace std; 
template <typename T>
class mapNode{
    public :
    string key;
    T value;
    mapNode<T>* next;
    mapNode(string key,T value){
        this->key=key;
        this->value=value;
        this->next=NULL;
    }
    ~mapNode(){
        delete next;
    }
};
template <typename T>
class map{
    mapNode<T>** bucket;
    int size;
    int numBucket;
    map(int size,int numBucket){
        this->size=size;
        this->numBucket=numBucket;
        bucket=new mapNode<T>*[numBucket];
        for(int i=0;i<numBucket;i++){
            bucket[i]=NULL;
        } 
    }
    ~map(){
       for(int i=0;i<numBucket;i++){
            delete bucket[i];
        } 
        delete [] bucket;
    }
    int getSize(){
        return size;
    }
    private:
    int getBucketIndex(string key){
        int hashCode=0;
        int p=1;
        for(int i=key.size()-1;i>=0;i--){
            hashCode +=key[i]*p;
            hashCode%=numBucket;
            p*=37;
            p%=numBucket;
        }
        return hashCode % numBucket;
    }
    void rehash(){
        mapNode<T>**temp=bucket;
        bucket=new mapNode<T>[numBucket*2];
        for(int i=0;i<2*numBucket;i++){
            bucket[i]=NULL;
        }
        int oldNumBucket=numBucket;
        numBucket*=2;
        size=0;
        for(int i=0;i<oldNumBucket;i++){
            mapNode<T>* head=temp[i];
            while(head){
                string key=head->key;
                T value=head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<oldNumBucket;i++){
            mapNode<T>* head=temp[i];
            delete temp[i];
        }
        delete [] temp;
    }
    public:
    T getValue(string key){
        int index=getBucketIndex(key);
        mapNode<T>* head =bucket[index];
        while(head){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return -1;
    }
    void insert(string key,T value){
        int index=getBucketIndex(key);
        mapNode<T>* head =bucket[index];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head =bucket[index];
        mapNode<T>* newNode =new mapNode<T>(key,value);
        newNode->next=head;
        bucket[index]=newNode;
        size++;
        double loadFactor=(1.0*size)/numBucket;
        if(loadFactor>0.7){
            rehash();
        }
        return;
        
    }
    void remove(string key){
        int index=getBucketIndex(key);
        mapNode<T>* head =bucket[index];
        mapNode<T>* prev=NULL;
        while(head){
            if(head->key==key){
                if(prev==NULL){
                    bucket[index]=head->next;
                }
                else{
                    prev->next=head->next;
                }
                head->next=NULL;
                delete head;
                size--;
                return ;
            }
            prev=head;
            head=head->next;
        }
        cout<<"NOT FOUND"<<endl;
        return;
    }   

};
#include <iostream>
#include <string>
#include <list>

class ParentSubject{
protected:
	int parentValue;
public:
	void setParentValue(int n){ parentValue = n; }
	int getParentValue(){ return parentValue; }
	ParentSubject(int v):parentValue(v){}
};

class Observer{
private:
	int id;
public:
	void notified( ParentSubject * ps, int pVal, int cVal){
		std::cout << "Observer "<< id << " notified that the new parent and child values are ";
		std::cout << pVal << " and " << cVal << std::endl;
	}
	Observer(int id):id(id){}
};

class Subject : public ParentSubject{
private:
	int childValue;
	std::list<Observer *> observerList;
public:
	Subject(int p, int c):ParentSubject(p), childValue(c), observerList() {}

	int getChildValue(){ return childValue; }

	void notify(){
		std::list<Observer *>::const_iterator ptr = observerList.begin();
		while( ptr != observerList.end() ){
			(*ptr)->notified(this, childValue, parentValue);
			++ptr;
		}
		
	}

	void add(Observer * o){
		observerList.push_back(o);
	}
	
	void setBothValue(int p, int c){ 
		childValue = c;
		parentValue = p;
		notify();
	}

};

int main(){
	Observer * ob1 = new Observer(11);
	Observer * ob2 = new Observer(22);
	Observer * ob3 = new Observer(33);
	
	Subject s1(10, 20);
	s1.add(ob1);
	s1.add(ob2);

	s1.setBothValue(111, 222);
}


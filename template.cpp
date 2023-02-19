#include <iostream>
#include<vector>

using namespace std;

class Facade {
public:
	void info() {
		cout << "Facade is built\n";
	}
};

class Wall {
public:
	void info() {
		cout << "Wall is built\n";
	}
};

class Door {
public:
	void info() {
		cout << "Door is built\n";
	}
};

class Window {
public:
	void info() {
		cout << "Window is built\n";
	}
};

class Roof {
public:
	void info() {
		cout << "Roof is built\n";
	}
};

class House{
public:
	vector<Facade> f;
	vector<Wall> w;
	vector<Door> d;
	vector<Window> wd;
	vector<Roof> r;
	void info() {
		int i;
		for (i = 0; i < f.size(); ++i)  
			f[i].info();
		for (i = 0; i < w.size(); ++i) 
			w[i].info();
		for (i = 0; i < d.size(); ++i) 
			d[i].info();
		for (i = 0; i < wd.size(); ++i)  
			wd[i].info();
		for (i = 0; i < r.size(); ++i)  
			r[i].info();
	}
};

class HouseBuilder {
protected:
	House* h;
public:
	HouseBuilder() : h(0) {}
	virtual ~HouseBuilder() {}
	virtual void createHouse() {}
	virtual void buildFacade() {}
	virtual void buildWall() {}
	virtual void buildWindow() {}
	virtual void buildDoor() {}
	virtual void buildRoof() {}
	virtual House* getHouse() { return h; }
};

class RegularHouse : public HouseBuilder {
	void createHouse() { h = new House; }
	void buildFacade() { h->f.push_back(Facade()); }
	void buildWall() { h->w.push_back(Wall()); }
	void buildWindow() { h->wd.push_back(Window()); }
	void buildDoor() { h->d.push_back(Door()); }
	void buildRoof() { h->r.push_back(Roof()); }
};

class Builder
{
public:
	House* createHouse(HouseBuilder& house)
	{
		house.createHouse();
		house.buildFacade();
		house.buildWall();
		house.buildWindow();
		house.buildDoor();
		house.buildRoof();
		return(house.getHouse());
	}
};

int main() {

	Builder b;

	RegularHouse rh;

	House* house = b.createHouse(rh);
	cout << "Regular house: \n";
	house->info();


	return 0;
}
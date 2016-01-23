/*-----------------------------
* Ksenia Vais         321855835
* Ofir Traubas        301378782
-----------------------------*/
#include "block.h"
#include <iostream>
#include <string>
/*default constructor*/
Block::Block() {
	name_="none";
	ontable=0;
	clear=1;
}
/*gets the Blocks name*/
int Block::setisonTable(int num){
	ontable=num;
	return 1;
}
int Block::isclear() {
	if (clear==1) {
		return 1;
	}
	return 0;
}
int Block::isontable() {
	if (ontable==1)
		return 1;
	return 0;
}
int Block::setoriginalindex(int num) {
	originalindex=num;
	return 1;
}
int Block::getoriginalindex() {
	return originalindex;
}
std::string Block::getName() const
{
    return this->name_;
}
std::string Block::setName(const std::string& name) 
{
	name_= name;
	return this->name_;
}
int Block::isonindex() {
	return isonindex_;
}
Block& Block::setisonindex(int num) {
	isonindex_=num;
	return *this;
}

const Block& Block:: print() const
{
    std::string bl=name_+" ";
    std::cout<<bl;
    return *this;
}
int Block::setisclear(int num) {
	clear=num;
	return 1;
}

Block::~Block() {
	
}


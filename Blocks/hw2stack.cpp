/*-----------------------------
* Ksenia Vais         321855835
* Ofir Traubas        301378782
-----------------------------*/
#include "arm.h"
#include <conio.h>
#include <Windows.h>
#include "block.h"
#include "hw2stack.h"
#include <iostream>
#include <stdio.h>
#include <string>

hw2stack::hw2stack() {

}
hw2stack::hw2stack(int num) {
	index=0;
	int i;
	blocksontable=0;
	blocksarray=new Block*[num];
	for (i=0;i<num;i++) {
		blocksarray[i]=new Block[num];
	}
}
/*hw2stack& hw2stack::STACK(const Block& A,const Block& B)  {
	std::string name1;	
	std::string name2;
	std::string output;
	name1=A.getName();
	name2=B.getName();
	output="STACK("+name1+","+name2+")";
	operators.push(output);
	return *this;
}*/
hw2stack& hw2stack::addBlock(int num,std::string name) {
	this->blocksarray[0][num].setoriginalindex(num);
	this->blocksarray[0][num].setName(name);
	this->blocksarray[0][num].setisonindex(num);
	index+=1;
	return *this;
}
Block& hw2stack::getBlock(std::string name) {
	int i;
	for (i=0;i<index;i++) {
		if (this->blocksarray[0][i].getName()==name) {
			return this->blocksarray[0][i];
		}
		
	}
	return this->arm.HOLDING();
}
Block& hw2stack::getBlock(int i) {
	return this->blocksarray[0][i];
}
hw2stack& hw2stack::ONTABLE(Block& A) {
	std::string output;
	std::string name;
	blocksontable+=1;
	A.setisonindex(0);
	if (blocksontable>index) {
		blocksontable-=1;
		std::cout<<"can't put anymore blocks on table"<<std::endl;
		return *this;
	}
	
	A.setisonTable(1);
	A.setisonindex(A.getoriginalindex());
	
	return *this;
}
hw2stack& hw2stack::operator^(hw2stack& stack) {
	std::string out1;
	std::string out2;
	out1=this->operators.top();
	this->operators.pop();
	out2=this->operators.top();
	this->operators.pop();
	this->operators.push(out1+"^"+out2);
	std::cout<< out1+"^"+out2;
	return *this;
}
std::string hw2stack::top() {
	return operators.top();
}
hw2stack& hw2stack::push(std::string str) {
	operators.push(str);
	return *this;
}
hw2stack hw2stack::pop() {
	operators.pop();
	return *this;
}
hw2stack& hw2stack::doOperator(std::string operation) {
	unsigned int i;
	std::string temp1;
	std::string temp2;
	std::string temp3;
	std::string output;
	std::stack<std::string> tempstack;
	std::stack<std::string> tempstack2;
	i=0;
	while (i<=operation.length()) {
			
			if (i==operation.length())
				break;
			if (i==operation.length()-1){
				temp1=operation[i];
				if (this->getBlock(temp1).isontable() || this->getBlock(temp1).getoriginalindex()!=this->getBlock(temp1).isonindex()) {
					i++;
					continue;
				}
				output=getBlock(temp1).getName();
				operators.push(output);
				i++;
			}
			else {
				temp1=operation[i];
				temp2=operation[i+1];
				output=getBlock(temp1).getName()+getBlock(temp2).getName();
				operators.push(output);
				i++;
			}
		}
	i=operation.length()-1;
		while (i>=0) {
			
			if (i==-1)
				break;
			if (i==operation.length()-1){
				temp1=operation[i];
				if (this->getBlock(temp1).isontable() || this->getBlock(temp1).getoriginalindex()!=this->getBlock(temp1).isonindex()) {
					i--;
					continue;
				}
				ONTABLE(getBlock(temp1));
				i--;
			}
			else {
				temp1=operation[i];
				temp2=operation[i+1];
				ON(getBlock(temp1),getBlock(temp2));
				i--;
			}
		}
		
		
	
	return *this;
}

hw2stack& hw2stack::print() {
	std::stack<std::string> temp;
	std::string temp2;
	while (!this->operators.empty()){
		temp2=this->operators.top();
		std::cout << temp2 << std::endl;
		temp.push(temp2);
		this->operators.pop();
	}
	while (!temp.empty()) {
		temp2=temp.top();
		this->operators.push(temp2);
		temp.pop();
	}
	return *this;
}
hw2stack& hw2stack::printtable() {//needs fixing
	int i;
	int j;
	int flag=0;
	int flag1=0;
	int flag2=0;
	std::string temp;
	for (i=index-1;i>=-1;i--) {
		for (j=0;j<index;j++) {
			if (blocksarray[0][j].isontable())
				
			if (blocksarray[0][j].isontable()) {
				if (i==-1) {
					std::cout<<"==";
					flag2=1;
					continue;
				}
				else if ((blocksarray[i][j].getName()=="none" && j!=-1)) /*|| (flag==0 && blocksarray[i][j].getName()=="none" && j==0))*/ {

					std::cout<<"  ";
					flag1=1;
				}
				else if (blocksarray[i][j].getName()!="none" && j!=-1) {
					std::cout<<blocksarray[i][j].getName()<<" ";
					flag=1;
				}
			}
		}
		if (flag2!=0 &&j!=index-1)
			break;
		if (flag!=0 || (flag==0 && flag1==1))
			std::cout<<std::endl;
		flag=0;
	}
	if (blocksontable==1)
		std::cout<<"==";
	std::cout<<std::endl;
	
	if (blocksontable==2 || blocksontable==1) {
		std::cout<<"|  |"<<std::endl<<"|  |";
	}
	else {
		for(i=2;i>0;i--) {
			for (j=0;j<blocksontable;j++) {
				if (j==0) {
					std::cout<<"|";
				}
				else if (j==blocksontable-1)
					std::cout<<"  |";
				else {
					std::cout<<"  ";
				}
			}
			std::cout<<std::endl;
		}
	}
	return *this;
}
hw2stack& hw2stack::ON(Block& A, Block& B) {
	int i;
	int j;
	std::string output;
	j=B.isonindex();
	for (i=0;i<index;i++) {

		if (blocksarray[i][j].getName()=="none") {
			blocksarray[i][j].setName(A.getName());
			blocksarray[i][j].setoriginalindex(A.getoriginalindex());
			A.setisonindex(j);
			if (A.isontable()) {
				A.setisonTable(0);
				blocksontable--;
			}
			break;
		}
	}
	B.setisclear(0);
	
	return *this;
}
hw2stack& hw2stack::STACK(Block& A, Block& B) {
	int i;
	int j;
	std::string output;
	j=B.isonindex();
	for (i=0;i<index;i++) {
		if (blocksarray[i][j].getName()=="none") {
			blocksarray[i][j].setName(A.getName());
			A.setisonindex(j);
			if (A.isontable())
				A.setisonTable(0);
			else 
				arm.setempty();
			break;
		}
	}
	output="STACK("+A.getName()+","+B.getName()+")";
	operators.push(output);

	return *this;
}
hw2stack& hw2stack::isCLEAR(Block& A) {
	std::string output;
	output="CLEAR("+A.getName()+")";
	operators.push(output);
	return *this;
}

hw2stack& hw2stack::PICKUP(Block& A) {
	int j;
	j=A.isonindex();
	arm.PICKblockUP(A);
	blocksarray[0][j].setName("none");
	
	return *this;
}
hw2stack& hw2stack::PUTDOWN(Block& A) {
	std::string out;
	blocksarray[0][A.getoriginalindex()].setName(A.getName());	
	
	arm.PUTblockDOWN(A);
	out="PUTDOWN("+A.getName()+")";
	operators.push(out);
	return *this;
}
hw2stack& hw2stack::UNSTACK(Block& A, Block&B) {
	int j;
	int i;
	std::string out;
	j=A.isonindex();
	for (i=0;i<index;i++) {
		if (blocksarray[i][j].getName()==A.getName()) {
			blocksarray[i][j].setName("none");
		}
	}
	B.setisclear(1);
	arm.PICKblockUP(A);
	return *this;
}
std::string hw2stack::blockunder(Block& A) {
	int i;
	std::string out;
	for (i=0;i<index;i++) {
		if (blocksarray[i][A.isonindex()].getName()==A.getName()) {
			if (i==0)
				out="none";
			else
				out=blocksarray[i-1][A.isonindex()].getName();
			break;
		}
	}
	return out;
}
std::string hw2stack::blockabove(Block& A) {
	int i;
	std::string out;
	for (i=0;i<index;i++) {
		if (blocksarray[i][A.isonindex()].getName()==A.getName()) {
			if (i==index-1)
				out="none";
			else
				out=blocksarray[i+1][A.isonindex()].getName();
			break;
		}
	}
	return out;
}
hw2stack::~hw2stack() {
	int i;
	/*for (i=0;i<index;i++) {
	delete[] blocksarray[i];
	}	
	delete []blocksarray;*/
}
int hw2stack::getindex() {
	return index;
}
bool hw2stack::is_empty() {
	if (this->operators.empty())
		return 1;
	return 0;
}
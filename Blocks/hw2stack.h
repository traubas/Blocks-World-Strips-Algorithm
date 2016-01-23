/*-----------------------------
* Ksenia Vais         321855835
* Ofir Traubas        301378782
-----------------------------*/

#ifndef HW2STACK_H_INCLUDED
#define HW2STACK_H_INCLUDED
#include "arm.h"
#include "block.h"
#include <stack>
class hw2stack {
	public:
		hw2stack(); //constructor
		hw2stack(int num);
		hw2stack& addBlock(int num,std::string name);
		Block& getBlock(int i);
		Block& getBlock(std::string name);
		hw2stack& ONTABLE(Block& A);
		hw2stack& ON(Block& A, Block& B);
		hw2stack& STACK(Block& A, Block& B);
		hw2stack& UNSTACK(Block& A, Block&B);
		hw2stack& PICKUP(Block& A);
		hw2stack& PUTDOWN(Block& A);
		hw2stack& isCLEAR(Block& A);
		hw2stack& operator^(hw2stack& stack);
		hw2stack& doOperator(std::string operation);
		std::string blockunder(Block& A);
		std::string blockabove(Block& A);
		std::string top();
		hw2stack& push(std::string str);
		hw2stack pop();
		hw2stack& print();
		hw2stack& printtable();
		int getindex();
		bool is_empty();
		~hw2stack();
	private:
		Arm arm;
		int index; //size of blocksarray
		int blocksontable;
		Block** blocksarray;
		std::stack<std::string> operators;
};
#endif // HW2STACK_H_INCLUDED
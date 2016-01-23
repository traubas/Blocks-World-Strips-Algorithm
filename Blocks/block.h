/*-----------------------------
* Ksenia Vais         321855835
* Ofir Traubas        301378782
-----------------------------*/

#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include<string>
#include <iostream>



class Block {

    public:

		Block();
        std::string getName() const;//get the name of the block - don't know if necessary
		std::string setName(const std::string& name);
        int setisonTable(int num);// returns if the block is on table
		int isontable();
		int setisclear(int num);
		int isclear();
		int isonindex();
		int setoriginalindex(int num);
		int getoriginalindex();
		Block& setisonindex(int num);
		const Block& print() const;// print the block
		~Block();

    private:
		int originalindex;
		int isonindex_;
		int clear;
		int ontable;
        std::string name_; /*Blocks name*/
};


#endif // Block_H_INCLUDED

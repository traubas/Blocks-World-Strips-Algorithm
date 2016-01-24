/*-----------------------------
* Ksenia Vais         321855835
* Ofir Traubas        301378782
-----------------------------*/
#include "arm.h"
#include "block.h"
#include <iostream>
#include<string>

Arm::Arm() {
	B=new Block;
	arm_empty_=0;
}
Arm& Arm::PICKblockUP(Block& A) {
	B->setoriginalindex(A.getoriginalindex());
	B->setName(A.getName());
	A.setisonindex(-2);
	A.setisonTable(0);
	arm_empty_=0;
	return *this;
}
Arm& Arm::PUTblockDOWN(Block& A) {
	A.setisonindex(B->getoriginalindex());
	A.setisonTable(1);
	arm_empty_=1;
	B->setName("none");
	return *this;
}
Block& Arm::HOLDING() {
	return *B;
}
Arm& Arm::setempty() {
	B->setName("none");
	arm_empty_=1;
	return *this;
}
Arm& Arm::printarm() {
	int i;
	int j;
	for (i=0;i<3;i++) {
		for (j=0;j<5;j++) {
			if (i==0) {
				std::cout<<"_";
			}
			else if (i==1) {
				if (j==1) {
					if (B->getName()=="none") {
						std::cout<<" ";
					}
					else {
						std::cout<<B->getName();
					}
				}
				else if (j==0 || j==2 || j==4) {
					std::cout<<"|";
				}
				else {
					std::cout<<" ";
				}
			}
			else {
				if (j==4) {
					std::cout<<"|";
				}
				else {
					std::cout<<" ";
				}
			}
		}
		std::cout<<std::endl;
	}
	return *this;
}
Arm::~Arm() {
}
/*gets the name of the block which arm is holding*/


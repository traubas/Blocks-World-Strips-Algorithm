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
Arm::~Arm() {
}
/*gets the name of the block which arm is holding*/


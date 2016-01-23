/*-----------------------------
* Ksenia Vais         321855835
* Ofir Traubas        301378782
------------------------------*/

#ifndef ARM_H_INCLUDED
#define ARM_H_INCLUDED
#include "block.h"
#include<string>
#include <iostream>

class Arm {

    public:
		Arm();
		Arm& PICKblockUP(Block& A);
		Arm& PUTblockDOWN(Block& A);
		Block& HOLDING();
		Arm& setempty();
		~Arm();

    private:
		Block *B;
        bool arm_empty_;
        //Block b;

};


#endif // Arm_H_INCLUDED

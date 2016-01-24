/*-----------------------------
* Ksenia Vais         321855835
* Ofir Traubas        301378782
-----------------------------*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include "arm.h"

#include "block.h"
#include "hw2stack.h"
std::stack<std::string> STRIPS(hw2stack& initialstack,hw2stack& goalstack);


using namespace std;
int main() {
	hw2stack *initialstack;
	hw2stack *goalstack;
	std::stack<std::string> plan;
	std::stack<std::string> tempstack;

	int i;
	int blocks_number=0;
	//int goalBlocks_number=0;
	//int table_size=0;
	std::string operation;
	std::string goperation;

	/*this part is for saving the original colors of the console*/
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	 GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	/*until here*/

	/*while (table_size<=0 || table_size>5) {
		cout << "please enter table size ranging from 1 to 5:" << endl;
		cin >> table_size;
	}*/
	while (blocks_number<=0 || blocks_number>10) {
		cout <<"please enter number of blocks"<<endl;
		cin >> blocks_number;
	}
	initialstack=new hw2stack(blocks_number);
	for (int i=0;i<blocks_number;i++) {
		switch (i) {
			case 0: initialstack->addBlock(i,"A");
					break;
			case 1: initialstack->addBlock(i,"B");
					break;
			case 2: initialstack->addBlock(i,"C");
					break;
			case 3: initialstack->addBlock(i,"D");
					break;
			case 4: initialstack->addBlock(i,"E");
					break;
			case 5: initialstack->addBlock(i,"F");
					break;
			case 6: initialstack->addBlock(i,"G");
					break;
			case 7: initialstack->addBlock(i,"H");
					break;
			case 8: initialstack->addBlock(i,"I");
					break;
			case 9: initialstack->addBlock(i,"J");
					break;
		}
	}
	std::cout<<"the blocks are:";
	for (int i=0;i<blocks_number;i++) {
		initialstack->getBlock(i).print();
	}
	std::cout<<std::endl;

	std::cout<<"enter the initial state, enter 1 to continue:"<<endl;
	while (operation!="1") {
		std::cout<<">> ";
		std::cin >> operation;
		if (operation=="1")
			break;
		initialstack->doOperator(operation);
		std::cout<<std::endl;
	}


	std::cout << "the initial state is:" << std::endl;
	std::cout << std::endl;
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY); //sets text color to red
	initialstack->printtable();
	SetConsoleTextAttribute ( h, wOldColorAttrs); //sets the color back to normal
	getchar();
	getchar();
	////////////////////
    //get the final state

    std::cout<<"now enter the goal state"<<std::endl;
    	//while (blocks_number<=0 || blocks_number>10) {
		//cout <<"please enter number of blocks"<<endl;
		//cin >> blocks_number;
	//}
	goalstack=new hw2stack(blocks_number);
	for (int i=0;i<blocks_number;i++) {
		switch (i) {
			case 0: goalstack->addBlock(i,"A");
					break;
			case 1: goalstack->addBlock(i,"B");
					break;
			case 2: goalstack->addBlock(i,"C");
					break;
			case 3: goalstack->addBlock(i,"D");
					break;
			case 4: goalstack->addBlock(i,"E");
					break;
			case 5: goalstack->addBlock(i,"F");
					break;
			case 6: goalstack->addBlock(i,"G");
					break;
			case 7: goalstack->addBlock(i,"H");
					break;
			case 8: goalstack->addBlock(i,"I");
					break;
			case 9: goalstack->addBlock(i,"J");
					break;
		}
	}
	std::cout<<"the blocks are:";
	for (int i=0;i<blocks_number;i++) {
		goalstack->getBlock(i).print();
	}
	std::cout<<std::endl;

	std::cout<<"enter the goal state, enter 1 to continue:"<<endl;
	while (goperation!="1") {
		std::cout<<">>";
		std::cin >> goperation;
		if (goperation=="1")
			break;
		goalstack->doOperator(goperation);
		std::cout<<std::endl;
	}


	std::cout << "the goal state is:" << std::endl;
	std::cout << std::endl;
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY); //sets text color to red
	goalstack->printtable();
	SetConsoleTextAttribute ( h, wOldColorAttrs); //sets the color back to normal
	plan=STRIPS(*initialstack,*goalstack);
	std::cout<<"THE PLAN IS!!!!!! :"<<std::endl;
	while(!plan.empty()) {
		tempstack.push(plan.top());
		plan.pop();
	}
	i=1;
	while(!tempstack.empty()) {
		std::cout<<i<<". "<<tempstack.top()<<std::endl;
		plan.push(tempstack.top());
		tempstack.pop();
		i++;
	}
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	initialstack->printtable();
	SetConsoleTextAttribute ( h, wOldColorAttrs); 
	getchar();
	return 0;
}

void checkStack(hw2stack& goalstack) { //print the goalstack function
	std::stack<std::string> temp1;
	/*this part is for saving the original colors of the console*/
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	 GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	/*until here*/
	std::cout<<"the goalstack is:"<<std::endl;
	while(!goalstack.is_empty()) {
		if (goalstack.top()[0]=='P' || goalstack.top()[0]=='S' || goalstack.top()[0]=='U') {
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout<<goalstack.top();
			SetConsoleTextAttribute ( h, wOldColorAttrs); 
		}
		else {
			std::cout<<goalstack.top();
		}
		temp1.push(goalstack.top());
		goalstack.pop();
		std::cout<<std::endl;
	}
	while(!temp1.empty()) {
		goalstack.push(temp1.top());
		temp1.pop();
	}
	
	getchar();
	return;
}
std::string findinstack(std::string A,std::stack<std::string> B) {
	std::string out;
	while (!B.empty()) {
		if (B.top().length()>1) {
			if (B.top()[0]==A[0]) {
				out=B.top()[1];
				return out;
			}
		}
		B.pop();
	}
	return A;
}

std::stack<std::string> STRIPS(hw2stack& initialstack,hw2stack& goalstack) {
	static std::stack<std::string> plan;
	static std::stack<std::string> teststack;
	static std::stack<std::string> tempstack;
	std::string originalblock;
	std::string currentblock;
	std::string blockabove;
	std::string blockunder;
	std::string currentblock1;
	std::string currentblock2;
	std::string blockabove1;
	std::string blockabove2;
	std::string blockunderfirst;
	std::string blockundersecond;
	std::string firstblock;
	std::string secondblock;
	std::string temp2;
	std::string temp3;
	hw2stack temp1;
	bool satisfied=FALSE;

	while (!goalstack.is_empty()) {
		teststack.push(goalstack.top());
		tempstack.push(goalstack.top());
		goalstack.pop();
	}
	while(!tempstack.empty()) {
		goalstack.push(tempstack.top());
		tempstack.pop();
	}
	if (goalstack.is_empty()) {
		return plan;
	}
	
	else if (goalstack.top().length()==1) { //if the operation is ONTABLE("BLOCK")
			originalblock=goalstack.top();
			currentblock=goalstack.top();
			blockunder=initialstack.blockunder(initialstack.getBlock(currentblock));
			blockabove=initialstack.blockabove(initialstack.getBlock(currentblock));;
			if (initialstack.getBlock(currentblock).isontable()) {//if its statisfied
				
				checkStack(goalstack);
				goalstack.pop();
			}

			else {//if its not on the table
				checkStack(goalstack);
				goalstack.pop();
				checkStack(goalstack);
				goalstack.push("PUTDOWN("+originalblock+")");
				checkStack(goalstack);
				goalstack.push("HOLDING("+originalblock+")");
				checkStack(goalstack);
				checkStack(goalstack);
				if (initialstack.getBlock(originalblock).isclear()) {//if its clear
					goalstack.pop();
					checkStack(goalstack);
					goalstack.push("UNSTACK("+originalblock+","+blockunder+")");
					checkStack(goalstack);
					goalstack.push("CLEAR("+originalblock+")");
					checkStack(goalstack);
					goalstack.push("ARMEMPTY");
					checkStack(goalstack);
					
					goalstack.pop();
					initialstack.UNSTACK(initialstack.getBlock(originalblock),initialstack.getBlock(blockunder));
					initialstack.printtable();
					plan.push("UNSTACK("+originalblock+","+blockunder+")");
					checkStack(goalstack);
					goalstack.pop();
					checkStack(goalstack);
					goalstack.pop();
					checkStack(goalstack);
					initialstack.PUTDOWN(initialstack.getBlock(originalblock));
					initialstack.printtable();
					plan.push("PUTDOWN("+originalblock+")");
					goalstack.pop();
				}
				else {//not clear and not on table
					while (satisfied==FALSE) {
						if (initialstack.getBlock(currentblock).isclear()) {//if block clear now
							satisfied=TRUE;
							while(currentblock!=originalblock) {
								checkStack(goalstack);
								goalstack.pop();
								checkStack(goalstack);
								goalstack.pop();
								checkStack(goalstack);
								goalstack.pop();
								checkStack(goalstack);
								initialstack.UNSTACK(initialstack.getBlock(currentblock),initialstack.getBlock(blockunder));
								initialstack.printtable();
								plan.push("UNSTACK("+currentblock+","+blockunder+")");
								temp3=findinstack(currentblock,teststack);
								if (currentblock!=temp3) {
									initialstack.STACK(initialstack.getBlock(currentblock),initialstack.getBlock(temp3[1]));
									initialstack.printtable();
									plan.push("STACK("+currentblock+","+temp3+")");
								}
								else {
									initialstack.PUTDOWN(initialstack.getBlock(currentblock));
									initialstack.printtable();
									plan.push("PUTDOWN("+currentblock+")");
								}
								currentblock=blockunder;
								blockunder=initialstack.blockunder(initialstack.getBlock(currentblock));
							}
							
							goalstack.pop();
							checkStack(goalstack);
							goalstack.pop();
							checkStack(goalstack);
							initialstack.UNSTACK(initialstack.getBlock(currentblock),initialstack.getBlock(blockunder));
							initialstack.printtable();
							plan.push("UNSTACK("+currentblock+","+blockunder+")");
							initialstack.PUTDOWN(initialstack.getBlock(currentblock));
							initialstack.printtable();
							plan.push("PUTDOWN("+currentblock+")");
							break;

						}
						else {//if the block above is not clear
							goalstack.push("UNSTACK("+blockabove+","+currentblock+")");
							checkStack(goalstack);
							goalstack.push("ARMEMPTY");
							checkStack(goalstack);
							goalstack.push("CLEAR("+blockabove+")");
							checkStack(goalstack);
							blockunder=currentblock;
							currentblock=blockabove;
							blockabove=initialstack.blockabove(initialstack.getBlock(currentblock));
						}
					}
				}
			}
		}
		else//ON situation
        { //if the operation is ONTABLE("BLOCK")
			satisfied=0;
            originalblock=goalstack.top();
            firstblock=originalblock[0];
            secondblock=originalblock[1];
            currentblock1=originalblock[0];
            currentblock2=originalblock[1];
            blockunderfirst=initialstack.blockunder(initialstack.getBlock(currentblock1));
            blockundersecond=initialstack.blockunder(initialstack.getBlock(currentblock2));
            blockabove1=initialstack.blockabove(initialstack.getBlock(currentblock1));
            blockabove2=initialstack.blockabove(initialstack.getBlock(currentblock2));

			
			if ((initialstack.getBlock(secondblock).isontable())&&(initialstack.blockunder(initialstack.getBlock(firstblock))==secondblock)) {//if its statisfied
				checkStack(goalstack);
				goalstack.pop();
				checkStack(goalstack);
			}

			else {//if its not on the table
				checkStack(goalstack);
				goalstack.pop();
				checkStack(goalstack);
				goalstack.push("STACK("+firstblock+","+secondblock+")");
				checkStack(goalstack);
				goalstack.push("HOLDING("+firstblock+")");
				checkStack(goalstack);
				goalstack.push("CLEAR("+secondblock+")");
				checkStack(goalstack);
				if (!initialstack.getBlock(secondblock).isclear()) {//if its clear
					
					while (satisfied==FALSE) {
						if (initialstack.getBlock(currentblock2).isclear()) {//if block clear now
							satisfied=TRUE;
							while(currentblock2!=secondblock) {
								checkStack(goalstack);
								checkStack(goalstack);
								goalstack.pop();
								checkStack(goalstack);
								goalstack.pop();
								checkStack(goalstack);
								goalstack.pop();
								checkStack(goalstack);
								initialstack.UNSTACK(initialstack.getBlock(currentblock2),initialstack.getBlock(blockundersecond));
								initialstack.printtable();
								plan.push("UNSTACK("+currentblock2+","+blockundersecond+")");
								initialstack.PUTDOWN(initialstack.getBlock(currentblock2));
								initialstack.printtable();
								plan.push("PUTDOWN("+currentblock2+")");
								currentblock2=blockundersecond;
								blockundersecond=initialstack.blockunder(initialstack.getBlock(currentblock2));
							}
							
							break;
						}
						else {//if the block above is not clear
							
							goalstack.push("UNSTACK("+blockabove2+","+currentblock2+")");
							checkStack(goalstack);
							goalstack.push("ARMEMPTY");
							checkStack(goalstack);
							goalstack.push("CLEAR("+blockabove2+")");
							checkStack(goalstack);
							blockundersecond=currentblock2;
							currentblock2=blockabove2;
							blockabove2=initialstack.blockabove(initialstack.getBlock(currentblock2));
							
						}
					}
				}
				satisfied=FALSE;
				
				if (initialstack.getBlock(firstblock).isclear()) {//if its clear
					if (initialstack.getBlock(firstblock).isontable()) {
						checkStack(goalstack);
						goalstack.pop();
						checkStack(goalstack);
						goalstack.push("PICKUP("+firstblock+")");
						checkStack(goalstack);
						goalstack.push("CLEAR("+firstblock+")");
						checkStack(goalstack);
						goalstack.push("ARMEMPTY");
						checkStack(goalstack);
						initialstack.PICKUP(initialstack.getBlock(firstblock));
						initialstack.printtable();
						goalstack.pop();
						plan.push("PICKUP("+firstblock+")");
						checkStack(goalstack);
						goalstack.pop();
						checkStack(goalstack);
						goalstack.pop();
						checkStack(goalstack);
						initialstack.STACK(initialstack.getBlock(firstblock),initialstack.getBlock(secondblock));
						initialstack.printtable();
						goalstack.pop();
						checkStack(goalstack);
						goalstack.pop();
						checkStack(goalstack);
						plan.push("STACK("+firstblock+","+secondblock+")");
						
					}
					else {
						checkStack(goalstack);
						goalstack.pop();
						checkStack(goalstack);
						goalstack.push("UNSTACK("+firstblock+","+blockunderfirst+")");
						checkStack(goalstack);
						goalstack.push("CLEAR("+firstblock+")");
						checkStack(goalstack);
						goalstack.push("ARMEMPTY");
						checkStack(goalstack);
						initialstack.UNSTACK(initialstack.getBlock(firstblock),initialstack.getBlock(blockunderfirst));
						goalstack.pop();
						plan.push("UNSTACK("+firstblock+","+blockunderfirst+")");
						initialstack.printtable();
						checkStack(goalstack);
						goalstack.pop();
						checkStack(goalstack);
						goalstack.pop();
						initialstack.STACK(initialstack.getBlock(firstblock),initialstack.getBlock(secondblock));
						plan.push("STACK("+firstblock+","+secondblock+")");
						initialstack.printtable();
						goalstack.pop();
						checkStack(goalstack);
						goalstack.pop();
						checkStack(goalstack);
					}
				}
				else {//not clear 
					while (satisfied==FALSE) {
						if (initialstack.getBlock(currentblock1).isclear()) {//if block clear now
							satisfied=TRUE;
							while(currentblock1!=firstblock) {
								checkStack(goalstack);
								checkStack(goalstack);
								goalstack.pop();
								checkStack(goalstack);
								goalstack.pop();
								checkStack(goalstack);
								goalstack.pop();
								checkStack(goalstack);
								initialstack.UNSTACK(initialstack.getBlock(currentblock1),initialstack.getBlock(blockunderfirst));
								plan.push("UNSTACK("+currentblock1+","+blockunderfirst+")");
								initialstack.printtable();
								initialstack.PUTDOWN(initialstack.getBlock(currentblock1));
								plan.push("PUTDOWN("+currentblock1+")");
								initialstack.printtable();
								currentblock1=blockunderfirst;
								blockunderfirst=initialstack.blockunder(initialstack.getBlock(currentblock1));
							}
							goalstack.pop();
							checkStack(goalstack);
							goalstack.pop();
							checkStack(goalstack);
							if (initialstack.getBlock(currentblock1).isontable()) {
								initialstack.PICKUP(initialstack.getBlock(currentblock1));
								plan.push("PICKUP("+currentblock1+")");
								initialstack.printtable();
							}
							else {
							initialstack.UNSTACK(initialstack.getBlock(currentblock1),initialstack.getBlock(blockunderfirst));
							plan.push("UNSTACK("+currentblock1+","+blockunderfirst+")");
							}
							initialstack.printtable();
							goalstack.pop();
							checkStack(goalstack);
							initialstack.STACK(initialstack.getBlock(currentblock1),initialstack.getBlock(secondblock));
							plan.push("STACK("+currentblock1+","+secondblock+")");
							initialstack.printtable();
							checkStack(goalstack);
							
							break;

						}
						else {//if the block above is not clear
							goalstack.push("UNSTACK("+blockabove1+","+currentblock1+")");
							checkStack(goalstack);
							goalstack.push("ARMEMPTY");
							checkStack(goalstack);
							goalstack.push("CLEAR("+blockabove1+")");
							checkStack(goalstack);
							blockunderfirst=currentblock1;
							currentblock1=blockabove1;
							blockabove1=initialstack.blockabove(initialstack.getBlock(currentblock1));
						}
					}
				}
			}
		}
		
		plan=STRIPS(initialstack,goalstack);
	return plan;
	

}

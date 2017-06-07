#include"TextProcessor.h"
int main()
{
	TextProcessor t("text1");
	DynamicArr<Transformation*> d;
	Transformation*  capital = new Capital;
	d.addEl(capital);
	
	TextProcessor t2("text2", d);
	
	t2 += ("addSome text");
	Transformation* swapChar = new CharSwap('E','m');
	t2 += swapChar;
	std::cout << t2;
//	Transformation* str = new StringSwap("t", "aa");

	std::cout << std::endl << t2[3];
	//d.removeEl(1);
	/*t2 -= 1;
	std::cout << std::endl << t2 << std::endl;
	-t2;
	std::cout  << t2 << std::endl;
	-t2;
	std::cout << t2 << std::endl;*/
	//TextProcessor t3("text3");
	//t3 += str;
	//std::cout << t3;

}
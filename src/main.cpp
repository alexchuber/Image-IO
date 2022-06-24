#include "File.h"

int main() 
{
	File car("input/car.tga");
	File circles("input/circles.tga");
	File layer_blue("input/layer_blue.tga");
	File layer_green("input/layer_green.tga");
	File layer_red("input/layer_red.tga");
	File layer1("input/layer1.tga");
	File layer2("input/layer2.tga");
	File pattern1("input/pattern1.tga");
	File pattern2("input/pattern2.tga");
	File text("input/text.tga");
	File text2("input/text2.tga");
	
	File EXAMPLE_part1("examples/EXAMPLE_part1.tga");
	File EXAMPLE_part2("examples/EXAMPLE_part2.tga");
	File EXAMPLE_part3("examples/EXAMPLE_part3.tga");
	File EXAMPLE_part4("examples/EXAMPLE_part4.tga");
	File EXAMPLE_part5("examples/EXAMPLE_part5.tga");
	File EXAMPLE_part6("examples/EXAMPLE_part6.tga");
	File EXAMPLE_part7("examples/EXAMPLE_part7.tga");
	File EXAMPLE_part8_r("examples/EXAMPLE_part8_r.tga");
	File EXAMPLE_part8_g("examples/EXAMPLE_part8_g.tga");
	File EXAMPLE_part8_b("examples/EXAMPLE_part8_b.tga");
	File EXAMPLE_part9("examples/EXAMPLE_part9.tga");
	File EXAMPLE_part10("examples/EXAMPLE_part10.tga");
	
	
	//Task 1
	File part1;
	part1.Multiply(layer1, pattern1);
	part1.WriteTo("output/part1.tga");

	if (part1 == EXAMPLE_part1)
		cout << "Task 1 successful!" << endl;
	else
		cout << "Task 2 failed." << endl;

	//Task 2
	File part2;
	part2.Subtract(layer2, car);
	part2.WriteTo("output/part2.tga");

	if (part2 == EXAMPLE_part2)
		cout << "Task 2 successful!" << endl;
	else
		cout << "Task 2 failed." << endl;

	//Task 3
	File part3a;
	part3a.Multiply(layer1, pattern2);
	File part3;
	part3.Screen(text, part3a);
	part3.WriteTo("output/part3.tga");

	if (part3 == EXAMPLE_part3)
		cout << "Task 3 successful!" << endl;
	else
		cout << "Task 3 failed." << endl;
	
	//Task 4
	File part4a;
	part4a.Multiply(layer2, circles);
	File part4;
	part4.Subtract(pattern2, part4a);
	part4.WriteTo("output/part4.tga");

	if (part4 == EXAMPLE_part4)
		cout << "Task 4 successful!" << endl;
	else
		cout << "Task 4 failed." << endl;

	//Task 5
	File part5;
	part5.Overlay(layer1, pattern1);
	part5.WriteTo("output/part5.tga");

	if (part5 == EXAMPLE_part5)
		cout << "Task 5 successful!" << endl;
	else
		cout << "Task 5 failed." << endl;

	//Task 6
	File part6 = car;
	part6.AddToGreenChannel(200);
	part6.WriteTo("output/part6.tga");

	if (part6 == EXAMPLE_part6)
		cout << "Task 6 successful!" << endl;
	else
		cout << "Task 6 failed." << endl;
	
	//Task 7
	File part7 = car;
	part7.ScaleRedChannel(4.f);
	part7.ScaleBlueChannel(0.f);
	part7.WriteTo("output/part7.tga");


	if (part7 == EXAMPLE_part7)
		cout << "Task 7 successful!" << endl;
	else
		cout << "Task 7 failed." << endl;

	//Task 8
	File part8_r = car;
	part8_r.AllRedChannel();
	part8_r.WriteTo("output/part8_r.tga");

	File part8_g = car;
	part8_g.AllGreenChannel();
	part8_g.WriteTo("output/part8_g.tga");

	File part8_b = car;
	part8_b.AllBlueChannel();
	part8_b.WriteTo("output/part8_b.tga");

	if (part8_r == EXAMPLE_part8_r
		&& part8_g == EXAMPLE_part8_g
		&& part8_b == EXAMPLE_part8_b)
		cout << "Task 8 successful!" << endl;
	else
		cout << "Task 8 failed." << endl;

	//Task 9
	File part9;
	part9.Combine(layer_blue, layer_green, layer_red);
	part9.WriteTo("output/part9.tga");

	if (part9 == EXAMPLE_part9)
		cout << "Task 9 successful!" << endl;
	else
		cout << "Task 9 failed." << endl;

	//Task 10
	File part10 = text2;
	part10.Rotate180();
	part10.WriteTo("output/part10.tga");

	if (part10 == EXAMPLE_part10)
		cout << "Task 10 successful!" << endl;
	else
		cout << "Task 10 failed." << endl;

	return 0;
}
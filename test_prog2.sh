make
g++ -o compare compare.cpp

./prog2 < input1.txt > your_output1.txt
./compare standard_output1.txt your_output1.txt
./prog2 < input2.txt > your_output2.txt
./compare standard_output2.txt your_output2.txt
./prog2 < input3.txt > your_output3.txt
./compare standard_output3.txt your_output3.txt
./prog2 < input4.txt > your_output4.txt
./compare standard_output4.txt your_output4.txt
./prog2 < input5.txt > your_output5.txt
./compare standard_output5.txt your_output5.txt

#titania, 969*1256 px, máscara de 3*3
mkdir titania
#First num_thread = 1
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_10r_1t.png 10 1
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_100r_1t.png 100 1
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_1000r_1t.png 1000 1

#num_threads = 2
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_10r_2t.png 10 2
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_100r_2t.png 100 2
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_1000r_2t.png 1000 2

#num_threads = 4
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_10r_4t.png 10 4
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_100r_4t.png 100 4
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_1000r_4t.png 1000 4

#num_threads = 8
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_10r_8t.png 10 8
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_100r_8t.png 100 8
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_1000r_8t.png 1000 8

#num_threads = 10
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_10r_10t.png 10 10
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_100r_10t.png 100 10
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_1000r_10t.png 1000 10

#num_threads = 16
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_10r_16t.png 10 16
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_100r_10t.png 100 16
../filter ../imgs/titania.png ../tests/blur2.txt titania/titania_1000r_10t.png 1000 16

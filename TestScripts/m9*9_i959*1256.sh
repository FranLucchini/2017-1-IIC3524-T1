#titania, 969*1256 px, máscara de 9*9
mkdir titania9
#First num_thread = 1
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_10r_1t.png 10 1
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_20r_1t.png 20 1
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_40r_1t.png 40 1

#num_threads = 2
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_10r_2t.png 10 2
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_20r_2t.png 20 2
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_40r_2t.png 40 2

#num_threads = 4
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_10r_4t.png 10 4
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_20r_4t.png 20 4
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_40r_4t.png 40 4

#num_threads = 8
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_10r_8t.png 10 8
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_20r_8t.png 20 8
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_40r_8t.png 40 8

#num_threads = 10
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_10r_10t.png 10 10
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_20r_10t.png 20 10
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_40r_10t.png 40 10

#num_threads = 16
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_10r_16t.png 10 16
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_20r_10t.png 20 16
../filter ../imgs/titania.png ../tests/blur9.txt titania9/titania_40r_10t.png 40 16

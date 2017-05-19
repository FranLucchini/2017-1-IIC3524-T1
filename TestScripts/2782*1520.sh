#rubi, 2048*1024 px
mkdir rubi
#First num_thread = 1
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100r_1t.png 100 1
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_1000r_1t.png 1000 1
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_10000r_1t.png 10000 1
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100000r_1t.png 100000 1

#num_threads = 2
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100r_2t.png 100 2
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_1000r_2t.png 1000 2
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_10000r_2t.png 10000 2
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100000r_2t.png 100000 2

#num_threads = 4
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100r_4t.png 100 4
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_1000r_4t.png 1000 4
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_10000r_4t.png 10000 4
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100000r_4t.png 100000 4

#num_threads = 8
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100r_8t.png 100 8
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_1000r_8t.png 1000 8
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_10000r_8t.png 10000 8
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100000r_8t.png 100000 8

#num_threads = 10
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100r_10t.png 100 10
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_1000r_10t.png 1000 10
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_10000r_10t.png 10000 10
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100000r_10t.png 100000 10

#num_threads = 16
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100r_16t.png 100 16
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_1000r_10t.png 1000 16
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_10000r_10t.png 10000 16
../filter ../imgs/rubi.png ../tests/blur2.txt rubi/rubi_100000r_10t.png 100000 16

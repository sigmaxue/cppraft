# cppraft
## 安装protobuff
```
git clone https://github.com/google/protobuf.git
cd protobuf
./autogen.sh 
 ./configure
make 
sudo make install
```
## 编译cppraft
```
git clone git@github.com:sigmaxue/cppraft.git
git submodule update --init --recursive
mkdir build
cd build
cmake ..
make
```

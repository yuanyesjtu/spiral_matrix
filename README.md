# 一、描述
在row行col列的矩阵m中，以元素m[x][y]为中心，创建顺时针发散的螺旋矩阵。螺旋中心坐标对应的元素值为1，随着螺旋的发散，逐渐增加1。详见下图：<br>
![spiral_matrix](https://github.com/yuanyesjtu/spiral_matrix/blob/master/spiral_matrix.jpg)

图中矩阵行列数为5*5，螺旋中心等于矩阵中心。<br>
可以发现，赋值路线为：→↓←←↑↑ →→→↓↓↓←←←←↑↑↑↑ ...<br>
每次循环包括四个方向，分别是：右下左上。对于第iter_idx次循环，向右和向下分别赋值2*iter_idex-1次，向左向上分别赋值2*iter_idex次。<br>
注意：在赋值过程中，要判断是否超过矩阵边界；螺旋中心不一定是矩阵中心；当螺旋中心不是矩阵中心时，比如下图：<br>
![spiral_matrix1](https://github.com/yuanyesjtu/spiral_matrix/blob/master/spiral_matrix1.jpg)

图中矩阵行列数为5*4，螺旋中心不等于矩阵中心。缺失10、11、12、13、25位置，所以跳过这些位置赋值。（思考：如果跳过缺失位置，但必须连续赋值，怎么做？）

# 二、输入
第一行为矩阵的行列数：<br>
row col<br>
第二行为螺旋中心坐标：<br>
x y<br>

# 三、输出
输出为row行col列的矩阵m

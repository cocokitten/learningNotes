###**Tensorflow中的线性回归**

该线性回归的例子来自于[Stanford的课程CS20SI](https://web.stanford.edu/class/cs20si/syllabus.html)

接下来，我们将在Tensorflow中，根据问题实现一个非常简单易懂的线性回归模型。

####**问题：**

我们经常听到，保险公司通过附近的火灾和盗窃等因素来计算邻里的危险程度。那么，火灾和盗窃数量之间是否有关系，如果有，是否可以找到这个关系。

换句话说，我们是否能找到函数关系f，当x是火灾的数量时，y是盗窃的数量。即，``` y = f(x)``` 。

给定关系，如果我们获得某个地区的火灾数量，我们能否预测这个地区的盗窃数量。

####**数据集：**
Name：[Fire and Theft in Chicago](http://college.cengage.com/mathematics/brase/understandable_statistics/7e/students/datasets/slr/frames/slr05.html)

X =  fires per 1000 housing units
Y =  thefts per 1000 population


####**解决方案：**

首先，假设火灾和盗窃之间的关系是线性的：
我们需要找到标量参数w和b，使用均方误差作为损失函数。

```python
import tensorflow as tf 
import numpy as np 
import matplotlib.pyplot as plt 
import xlrd 

#第一步：从 .xls文件中读取数据
#python操作excel主要用到xlrd和xlwt这两个库，xlrd是读excel，xlwt是写excel的库
DATA_FILE = "data/fire_theft.xls"

# 打开excel
book = xlrd.open_workbook(DATA_FILE,encoding_override = "utf-8")  

#通过索引顺序，得到第一个工作表
sheet = book.sheet_by_index(0)  

#获取整行和整列的值（数组）,sheet.row_values(i)和sheet.col_values(i)
data = np.asarray([sheet.row_values(i) for i in range(1,sheet.nrows)])

#获取行数nrows=sheet.nrows和列数ncols=sheet.ncols
n_samples = sheet.nrows - 1

#第二步：创建占位符，输入X（火灾数量），Y（盗窃数量）
X = tf.placeholder(tf.float32, name="X")
Y = tf.placeholder(tf.float32, name="Y")

#第三步：创建权重和偏置权重，初始化为0
w = tf.Variable(0.0,name="weights")
b = tf.Variable(0.0,name="bias")

#第四步：创建模型，根据火灾的数量来预测Y（盗窃的数量）
Y_predicted = X * w + b 

#第五步：使用平方误差作为损失函数
loss = tf.square(Y - Y_predicted, name="loss")

#第六步：使用梯度下降，学习率0.01，来最小化损失函数
optimizer = tf.train.GradientDescentOptimizer(learning_rate = 0.001).minimize(loss)

with tf.Session() as sess:
	
	#第七步：初始化所有变量，w和b
	sess.run(tf.global_variables_initializer())

	#第八步：训练模型
	for i in range(100):
		for x, y in data:
			sess.run(optimizer, feed_dict={X:x,Y:y})
		#第九步：输出w和b的值
		w_value,b_value = sess.run([w,b])
		
#可以绘制结果
plt.figure('model')
X, Y = data.T[0], data.T[1]
plt.plot(X, Y, 'bo', label='Real Data')
plt.plot(X, X * w_value + b_value, 'r',label='Predicted data')
plt.legend()
plt.show()
plt.savefig('results.png')
```


![结果.jpg](http://upload-images.jianshu.io/upload_images/7079532-a0a732cc984bf5b3.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

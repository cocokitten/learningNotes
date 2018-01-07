1. ```tf.argmax```

返回指定维度（axis）上的最大值的位置索引。

```python
tf.argmax(input, axis=None, name=None, dimension=None)
```
* input ：张量，其类型必须为 float32, float64, int64, int32, uint8, uint16,int16, int8, complex64, complex128, qint8, quint8, qint32, half。

* axis：指定维度。为0时，返回每一列的最大值的位置索引；为1时，返回每一行的最大值的位置索引；多维张量时，以此类推。

例如：

当 axis = 0时，返回每一列的最大值的位置索引
```python
d = tf.constant([[0.3,0.2,0.4],[0.5,0.2,0.2]], name='d')
with tf.Session() as sess:
     print(sess.run(tf.argmax(d ,0)))  #>>[1 0 0]
```
当 axis = 1时，返回每一行的最大值的位置索引

```python
d = tf.constant([[0.3,0.2,0.4],[0.5,0.2,0.2]], name='d')
with tf.Session() as sess:
     print(sess.run(tf.argmax(d ,1)))  #>>[2 0]
```

2. ```tf.nn.softmax```

计算softmax回归，常用作多分类的输出层。
将神经网络的输出变为一个概率分布。

```python
tf.nn.softmax(logits, dim=-1, name=None)
```
* logits：非空张量，其类型必须为half、float32、float64

例如：
```python
d = tf.constant([[0.3,0.2,0.4],[0.5,0.2,0.2]], name='d')
d_ = tf.nn.softmax(d)

with tf.Session() as sess:
     print(sess.run(d_))

#输出：
>>[[ 0.33222499  0.30060959  0.36716539]
   [ 0.40295988  0.29852003  0.29852003]]
```
3. ```tf.nn.softmax_cross_entropy_with_logits```
```python
tf.nn.softmax_cross_entropy_with_logits( _sentinel=None, labels=None, logits=None, dim=-1, name=None)
```
4. ```tf.equal```

对比两个矩阵中的元素是否相等。返回张量，其类型为bool。

```python
tf.equal(x, y, name=None)
```
例如： 
```python
a = tf.constant([5.0,4.0,1.0], name='a')
b = tf.constant([0.8,0.1,1.0], name='b')

with tf.Session() as sess:
     print(sess.run(tf.equal(a,b)))

#输出：
[False False True]
```
5. ```tf.cast```

将张量投射为新的类型。

```python
tf.cast(x, dtype,name=None)
```
例如：基于上个例子
```python
a = tf.constant([5.0,4.0,1.0], name='a')
b = tf.constant([0.8,0.1,1.0], name='b')

results = tf.equal(a, b)

with tf.Session() as sess:
    print(sess.run(tf.cast(results, tf.float32)))

#输出：
[0. 0. 1.]
```

6. 在Tensor某一维度上求值的函数

* 求最大值
```python
tf.reduce_max(input_tensor, reduction_indices = None, keep_dim = False, name = None)
```
* 求平均值
```python
tf.reduce_mean(input_tensor, reduction_indices = None, keep_dim = False, name = None)
```
* 计算张量指定维度上的和
```python
tf.reduce_sum(input_tensor, reduction_indices = None, keep_dim = False, name = None)
```
```input_tensor```：待求tensor，```reduction_indices```：指定维度。

举例如下：

```python
x = [[1.,2.],[3.,4.]]

y1 = tf.reduce_mean(x,1)  #[ 1.5  3.5]
y2 = tf.reduce_mean(x,0)  #[ 2.  3.]
y3 = tf.reduce_mean(x)    # 2.5

o1 = tf.reduce_max(x,1)  #[ 2.  4.]
o2 = tf.reduce_max(x,0)  #[ 3.  4.]
o3 = tf.reduce_max(x)    # 4
```







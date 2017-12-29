### 一、在Tensor某一维度上求值的函数

* 求最大值
```python
tf.reduce_max(input_tensor, reduction_indices = None, keep_dim = False, name = None)
```
* 求平均值
```python
tf.reduce_mean(input_tensor, reduction_indices = None, keep_dim = False, name = None)
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





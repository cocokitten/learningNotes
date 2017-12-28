###**一、创建常量**

产生给定值的常量

``` tf​.​constant​(​value​,​ dtype​=​None​,​ shape​=​None​,​ name​=​'Const'​,​ verify_shape​=​False) ```

例如：
``` python
	a = tf.constant(10, name = "scalar")
	b = tf.constant([2,2], name = "vector") 
	c = tf.constant([[0,1],[2,3]], name = "matrix")
```
###**二、创建具有特定值的常量**

 - **创建值为全零的张量**
 
```tf​.​zeros​(​shape​,​ dtype​=​tf​.​float32​,​ name​=​None) ```

例如：
```python
   tf​.​zeros​([​2​,​ ​3​],​ tf​.​int32​)​ ​==>​ ​[[​0​,​ ​0​,​ ​0​],​ ​[​0​,​ ​0​,​ ​0​]]
```

- **创建形状（shape）和类型（dtype）与input_tensor相同的全零的张量**

```tf​.​zeros_like​(​input_tensor​,​ dtype​=​None​,​ name​=​None​,​ optimize​=​True) ```

例如：
```python
  # input_tensor 为 [0, 1], [2, 3], [4, 5]]
  tf​.​zeros_like​(​input_tensor​)​ ​==>​ ​[[​0​,​ ​0​],​ ​[​0​,​ ​0​],​ ​[​0​,​ ​0​]]
```

- **创建值为全1的张量**

```tf​.​ones​(​shape​,​ dtype​=​tf​.​float32​,​ name​=​None) ```

例如：
```python
   tf​.​ones​([​2​,​ ​3​],​ tf​.​int32​)​ ​==>​ ​[[​1​,​ ​1​,​ ​1​],​ ​[​1​,​ ​1​,​ ​1​]]
```

- **创建形状（shape）和类型（dtype）与input_tensor相同的全1的张量**

```tf​.​ones_like​(​input_tensor​,​ dtype​=​None​,​ name​=​None​,​ optimize​=​True) ```

例如：
```python
   # input_tensor 为 [0, 1], [2, 3], [4, 5]]
   tf​.​ones_like​(​input_tensor​)​ ​==>​ ​[[​1​,​ ​1​],​ ​[​1​,​ ​1​],​ ​[​1​,​ ​1​]]
```

- **创建一个张量，其所有元素值为给定的标量的值**

```tf​.​fill​(​dims​,​ value​,​ name​=​None​) ```

例如：
```python
   tf​.​ones​([​2​,​ ​3​],​ ​9​)​ ​==>​ ​[[​9​,​ ​9​,​ ​9​],​ ​[​9​,​ 9​,​ ​9​]]
```

###**三、创建序列常量**
- ```tf​.​lin_space​(​start​,​ stop​,​ num​,​ name​=​None) ```

生成指定区间[start, stop]内的值，即从start开始产生一系列均匀间隔的值。序列以stop-start/num-1递增。

```python
tf​.​lin_space​(​10.0​,​ ​13.0​,​ ​4​,​ name​=​"linspace"​)​ ​==>​ ​[​10.0​ ​11.0​ ​12.0​ ​13.0]
```
注意：start和stop必须是float32或float64类型，num必须为int32，int64类型

- ```tf​.​range​(​start​,​ limit​=​None​,​ delta​=​1​,​ dtype​=​None​,​ name​=​'range') ```

创建数字序列，区间为[start, limit)，以delta为增量。

``` python
# 'start' 为 3, 'limit' 为 18, 'delta' 为 3
tf​.​range​(​start​,​ limit​,​ delta​)​ ​==>​ ​[​3​,​ ​6​,​ ​9​,​ ​12​,​ ​15]
# 'start' 为 3, 'limit' 为 1, 'delta' 为 -0.5
tf​.​range​(​start​,​ limit​,​ delta​)​ ​==>​ ​[​3​,​ ​2.5​,​ ​2​,​ ​1.5]
# 'limit' 为 5
tf​.​range​(​limit​)​ ​==>​ ​[​0​,​ ​1​,​ ​2​,​ ​3​,​ ​4]
```

###**四、创建满足特定分布的随机常量**

```python
tf.random_normal(shape, mean=0.0, stddev=1.0, dtype=tf.float32, seed=None, name=None)
tf.truncated_normal(shape, mean=0.0, stddev=1.0, dtype=tf.float32, seed=None,name=None)
tf.random_uniform(shape, minval=0, maxval=None, dtype=tf.float32, seed=None,name=None)
tf.random_shuffle(value, seed=None, name=None)
tf.random_crop(value, size, seed=None, name=None)
tf.multinomial(logits, num_samples, seed=None, name=None)
tf.random_gamma(shape, alpha, beta=None, dtype=tf.float32, seed=None, name=None)
```

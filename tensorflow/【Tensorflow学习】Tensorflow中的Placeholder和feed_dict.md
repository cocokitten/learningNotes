Tensorflow程序通常有2个阶段：

 - 组装图
 - 使用会话来执行图中的操作

因此，在组装计算图的阶段，我们不一定必须提前知道所要计算的值。相当于定义x和y的函数， 而不知道x和y的值。例如，```f(x, y) = x*2 + y ``` 。 其中x和y就是实际值的占位符。

### Placeholder

要定义一个占位符，我们使用：
```python
tf​.​placeholder​(​dtype​,​ shape​=​None​,​ name​=​None)
```

其中，dtype 是指定placeholder值的数据类型的必须参数。

``` shape=None``` 意味着任何维度的张量都可以被接受，但是当我们进行调试时，未指定维度可能就会成为一个噩梦，所以应该始终尽可能详细的定义占位符的维度。

我们也可以给placeholder一个名字，就如Tensorflow中的其他op一样。

```python
# 创建一个类型为 float 32, 有三个元素的向量的占位符
a ​=​ tf​.​placeholder​(​tf​.​float32​,​ shape​=[​3​])

# 创建一个类型为float 32的常量
b ​=​ tf​.​constant​([​5​,​ ​5​,​ ​5​],​ tf​.​float32)

c ​=​ a ​+​ b 

# 如果试图得到（fetch）c的值，我们可能得到一个错误
with​ tf​.​Session​()​ ​as​ sess:
	print​(​sess​.​run​(​c​))
	>>​ ​NameError
```

因为，我们要计算c，前提是我们必须知道a的值，但是，目前a仅仅是一个占位符，并没有真实的值。所以，我们必须首先喂（feed）值给占位符a。

```python
with​ tf​.​Session​()​ ​as​ sess:
# 将[1, 2, 3] 喂给placeholder a，以字典的形式 {a: [1, 2, 3]}
# 获取c的值
	print​(​sess​.​run​(​c​,​ ​{​a​:​ ​[​1​,​ ​2​,​ ​3​]}))
	>>​ ​[​6.​ ​7.​ ​8.]
```

在上面的例子中，我们仅仅feed单个的值给placeholder， 如果我们需要feed多个值给placeholder，应该如何做呢？

通过迭代数据集，每次feed一个值。

```python
with​ tf​.​Session​()​ ​as​ sess:
	for​ a_value ​in​ list_of_a_values:
	print​(​sess​.​run​(​c​,​ ​{​a​:​ a_value​}))
```


我们也可以feed值给非占位符的张量，只要张量是feedable。

检查张量是否feedable：

```python
tf.Graph.is_feedable(tensor)
```

```python
a = tf.add(2, 5)
b = tf.mul(a, 3)

sess = tf.Session()

replace_dict = {a: 15}

sess.run(b, feed_dict=replace_dict) # returns 45
```

```feed_dict``` 可以非常有用的测试模型。当我们有一个很大的计算图，当你只想测试其中的一部分时，可以提供虚拟值，这样Tensorflow就不会浪费时间进行不必要的操作。

备注：
```python
tf.Session.run(fetches, feed_dict=None, options=None, run=metadate=None)
```

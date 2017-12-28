在Tensorflow中，变量的作用就是保存和更新神经网络的参数。和其他编程语言类似，Tensorflow中的变量也需要指定初始值。

###**一 声明变量**
```python
class tf.Variable 
```
```python
tf.Variable(initial_value=None, trainable=True, collections=None, validate_shape=True, caching_device=None, name=None, variable_def=None, dtype=None, excepted_shape=None, import_scope=None)
```
```python
a ​=​ tf​.​Variable​(​2​,​ name​=​"scalar"​)
b ​=​ tf​.​Variable​([​2​,​ ​3​],​ name​=​"vector"​)
c ​=​ tf​.​Variable​([[​0​,​ ​1​],​ ​[​2​,​ ​3​]],​ name​=​"matrix"​)
W ​=​ tf​.​Variable​(​tf​.​zeros​([​784​,​10​]))
```
通过构造类Variable的实例可以向Tensorflow的计算图中添加变量。在声明变量时，构造函数```tf.Variable() ``` 需要初始值，它可以是任何类型（dtype）和维度（shape）的张量。

类型（dtype）和维度（shape）是变量最重要的两个属性。

一个变量在构造之后，它的 **类型** 就 **不能** 再 **改变** 了。

维度是变量另一个重要的属性。和类型不同，**维度** 在变量构造后是 **可以改变** 的，但需要设置参数``` validate_shape = False``` 。


###**二 初始化变量**

在Tensorflow中，一个变量的值在被使用之前，这个变量的初始化过程需要被明确地调用。

- **初始化所有变量**

最简单的方法是使用 ```tf.global_variables_initializer() ``` 一次性初始化所有变量。

``` python
init ​=​ tf​.​global_variables_initializer​()
with​ tf​.​Session​()​ ​as​ sess:
	tf​.​run​(​init)
```
- **初始化部分变量**

给定要初始化的部分变量的列表，使用 ``` tf.variables_initializer()  ```  初始化部分变量。

```python
init_ab ​=​ tf​.​variables_initializer​([​a​,​ b​],​ name​=​"init_ab")
with​ tf​.​Session​()​ ​as​ sess:
	tf​.​run​(​init_ab)
```
- **初始化单个变量**

使用 ```tf.Variable.initializer ``` 初始化单个变量

```python
W ​=​ tf​.​Variable​(​tf​.​zeros​([​784​,​10​]))
with​ tf​.​Session​()​ ​as​ sess:
	tf​.​run​(​W​.​initializer)
```


###**三 输出变量的值**

如果我们输出初始化后的变量，我们只能看到tensor object。

```python
W ​=​ tf​.​Variable​(​tf​.​truncated_normal​([​700​,​ ​10​]))
with​ tf​.​Session​()​ ​as​ sess:
	sess​.​run​(​W​.​initializer)
	print​ W

>>​ ​Tensor​(​"Variable/read:0"​,​ shape​=(​700​,​ ​10​),​ dtype​=​float32)
```

要得到变量的值，使用 ```eval() ```

```python
W ​=​ tf​.​Variable​(​tf​.​truncated_normal​([​700​,​ ​10​]))

with​ tf​.​Session​()​ ​as​ sess:
	sess​.​run​(​W​.​initializer)
	print​ W​.​eval​()
	
>>​ ​[[-​0.76781619​ ​-​0.67020458​ ​1.15333688​ ​...,​ ​-​0.98434633​ ​-​1.25692499
​-​0.90904623]
​[-​0.36763489​ ​-​0.65037876​ ​-​1.52936983​ ​...,​ ​0.19320194​ ​-​0.38379928
​0.44387451]
​[​ ​0.12510735​ ​-​0.82649058​ ​0.4321366​ ​...,​ ​-​0.3816964​ ​0.70466036
​1.33211911]
​..., ​[​ ​0.9203397​ ​-​0.99590844​ ​0.76853162​ ​...,​ ​-​0.74290705​ ​0.37568584
​0.64072722]
​[-​0.12753558​ ​0.52571583​ ​1.03265858​ ​...,​ ​0.59978199​ ​-​0.91293705
​-​0.02646019]
​[​ ​0.19076447​ ​-​0.62968266​ ​-​1.97970271​ ​...,​ ​-​1.48389161​ ​0.68170643
​1.46369624​]]
```

###**四 赋值给变量**

初始化变量后，其值可以通过 Assign 方法修改。

使用 ```tf.Variable.assign() ``` 给变量赋值。

```python
W ​=​ tf​.​Variable​(​10​)
W​.​assign​(​100​)

with​ tf​.​Session​()​ ​as​ sess:
	sess​.​run​(​W​.​initializer)
	print​ W​.​eval​() 
	# >> 10 输出值为10
```
为什么w的值没有变为100呢？
```W​.​assign​(​100​) ``` 并没有讲100赋值给W，而是创建了一个赋值操作（assign op）来做这件事情，要使得该操作生效，我们必须在会话（Session）中执行该操作才行。
修改如下：

```python
W ​=​ tf​.​Variable​(​10​)
assign_op = W​.​assign​(​100​)
with​ tf​.​Session​()​ ​as​ sess:
	sess​.​run​(​assign_op)
	print​ W​.​eval​() # >> 100
```

###**四 简单的变量增加和减少**

Tensorflow提供如下两个方法：

```python
tf.Variable.assign_add()
tf.Variable.assign_sub()
```
```python
W = tf.Variable(10)
with tf.Session() as sess:
	sess.run(W.initializer)
	print sess.run(W.assign_add(10)) # >> 20
	print sess.run(W.assign_sub(2)) # >> 18
```

因为Tensorflow的会话分别地维护values。

```python
W = tf.Variable(10)

sess1 = tf.Session()
sess2 = tf.Session()

sess1.run(W.initializer)
sess2.run(W.initializer)

print sess1.run(W.assign_add(10)) # >> 20
print sess2.run(W.assign_sub(2)) # >> 8

print sess1.run(W.assign_add(100)) # >> 120
print sess2.run(W.assign_sub(50)) # >> -42

sess1.close()
sess2.close()
```

###**五 使用其他变量声明变量**

```python
W ​=​ tf​.​Variable​(​tf​.​truncated_normal​([​700​,​ ​10​]))
U ​=​ tf​.​Variable​(​W ​*​ ​2)
```

因为变量在使用之前必须被明确地初始化，所以，在该情况下，可以使用 ```initialized_value()  ``` 来确保W在其被使用之前，已经被初始化。

```python
U ​=​ tf​.​Variable​(​W​.​intialized_value​()​ ​*​ ​2)
```

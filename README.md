# Algorithm

## 最短路径
> 最短路径的核心思想就是能否通过第三点来改变另外两点之间的最短距离
### Floyd
遍历每一个点，判断在经过该点中转的情况下能否使两点间的路径变短
* 多源最短路径
* 邻接矩阵存图 
* $O(N^3)$
* 无法解决负权回路

### Dijkstra
每次选出离start最近的点，此时该点与start的距离已由“估计值”变为了“确定值”。然后对该点的出边进行松弛操作。其本质思想是**贪心**
* 单源最短路径
* 邻接表存图
* $O(N^2)$
* 不能含有负权边
> 为什么不能含有负权边？因为Dijkstra的条件是每次找出距离start最近的点，其他边权都为正时，该点的dist就不会再因为别的边而发生变化。含有负权时则打破了这条规则。

**堆优化：** 每次查找距离源点最近的点时可用堆来优化：用$O(logN)$的时间取出栈顶元素并删除，用$O(logN)$遍历每条边。时间复杂度可降到$O((M+N)logN)$

## 树
### 二叉搜索树
对于任意一个节点`x`，其左子树中的关键字最大不超过`x.data`，其右子树中的关键字最小不小于`x.data`
* 前序遍历
* 中序遍历
* 后序遍历

### 堆

## 字符串
### Manacher

马拉车算法 **Manacher's Algorithm** 是用来**查找一个字符串的最长回文子串**的**线性**方法，由一个叫 Manacher 的人在 1975 年发明的，这个方法的最大贡献是在于将时间复杂度提升到了线性。
1. **奇偶问题填充解决**
    对于奇偶字符串的处理，Manacher采用的是字符之间填充相同符号、字符串两端都加入不同字符的方法
    
    如字符串`“abbccbba”`，增加字符后变成`“@#a#b#b#c#c#b#b#a#0”`
    
    这样处理后，原来的字符串无论奇偶，都将变成奇字符串来处理。
    
2. **重定义字符串长度**
   字符串长度由`n`变为了`2 * n + 2`

3. **原字符串下标**

   ```
   $0#1#2#3#4@
   $a#b#c#b#a@
   0123456789
   ```

   显然，`原坐标 = （现坐标 - 1) / 2`

4. **计算最长回文子串长度**

     用`p[i]`表示以`s[i]`字符为中心的最长回文半径

     




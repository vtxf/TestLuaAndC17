--在Lua中定义两个变量  
arg1=15  
arg2=20  
  
--在Lua中定义一个表  
table=  
{  
    a=25,  
    b=30  
}  
  
--在Lua中定义一个求和的方法  
function sum(a,b)  
  return a+b  
end  
  
--在Lua中定义一个输出的方法  
function printf()  
  print("This is a function declared in Lua")  
end  

--在Lua中调用C++中定义并且注册的方法  
average,sum=AverageAndSum(20,52,75,14)  
print("Average="..average)  
print("Sum="..sum)  
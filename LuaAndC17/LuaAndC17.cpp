// LuaAndC17.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
//
//
//int main()
//{
//    return 0;
//}

using namespace std;

#include <iostream>  

extern "C" {
	#include "lua-5.3.4/src/lua.h"
	#include "lua-5.3.4/src/lualib.h"
	#include "lua-5.3.4/src/lauxlib.h"
}

using namespace std;

int main()
{
	//创建Lua环境  
	lua_State* L = luaL_newstate();
	//打开Lua标准库,常用的标准库有luaopen_base、luaopen_package、luaopen_table、luaopen_io、  
	//luaopen_os、luaopen_string、luaopen_math、luaopen_debug  
	luaL_openlibs(L);

	//下面的代码可以用luaL_dofile()来代替  
	//加载Lua脚本  
	luaL_loadfile(L, "script.lua");
	//运行Lua脚本  
	lua_pcall(L, 0, 0, 0);

	//将变量arg1压入栈顶  
	lua_getglobal(L, "arg1");
	//将变量arg2压入栈顶  
	lua_getglobal(L, "arg2");

	//读取arg1、arg2的值  
	int arg1 = lua_tonumber(L, -2);
	int arg2 = lua_tonumber(L, -1);

	//输出Lua脚本中的两个变量  
	cout << "arg1=" << arg1 << endl;
	cout << "arg2=" << arg2 << endl;

	//将函数printf压入栈顶  
	lua_getglobal(L, "printf");
	//调用printf()方法  
	lua_pcall(L, 0, 0, 0);

	//将函数sum压入栈顶  
	lua_getglobal(L, "sum");
	//传入参数  
	lua_pushinteger(L, 15);
	lua_pushinteger(L, 25);
	//调用printf()方法  
	lua_pcall(L, 2, 1, 0);//这里有2个参数、1个返回值  
						  //输出求和结果  
	cout << "sum=" << lua_tonumber(L, -1) << endl;

	//将表table压入栈顶  
	lua_getglobal(L, "table");
	//获取表  
	//lua_pushnumber(L, 1);
	lua_pushstring(L, "b");
	lua_gettable(L, -2);
	//输出表中第一个元素  
	cout << "table.a=" << lua_tonumber(L, -1) << endl;

}


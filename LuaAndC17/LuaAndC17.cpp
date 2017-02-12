// LuaAndC17.cpp : �������̨Ӧ�ó������ڵ㡣
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

static int AverageAndSum(lua_State *L)
{
	//����ջ��Ԫ�صĸ���  
	int n = lua_gettop(L);
	//�洢��Ԫ��֮��  
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		//�������ʹ���  
		if (!lua_isnumber(L, i))
		{
			//���������Ϣ  
			lua_pushstring(L, "Incorrect argument to 'average'");
			lua_error(L);
		}
		sum += lua_tonumber(L, i);
	}
	//����ƽ��ֵ  
	lua_pushnumber(L, sum / n);
	//�����  
	lua_pushnumber(L, sum);

	//����ֵ�ĸ���������Ϊ2  
	return 2;
}

int main()
{
	//����Lua����  
	lua_State* L = luaL_newstate();
	//��Lua��׼��,���õı�׼����luaopen_base��luaopen_package��luaopen_table��luaopen_io��  
	//luaopen_os��luaopen_string��luaopen_math��luaopen_debug  
	luaL_openlibs(L);

	// ��C++��ʹ��lua_register()������ɶԸ÷�����ע��
	lua_register(L, "AverageAndSum", AverageAndSum);

	//����Ĵ��������luaL_dofile()������  
	//����Lua�ű�  
	luaL_loadfile(L, "script.lua");
	//����Lua�ű�  
	lua_pcall(L, 0, 0, 0);

	//������arg1ѹ��ջ��  
	lua_getglobal(L, "arg1");
	//������arg2ѹ��ջ��  
	lua_getglobal(L, "arg2");

	//��ȡarg1��arg2��ֵ  
	int arg1 = lua_tonumber(L, -2);
	int arg2 = lua_tonumber(L, -1);

	//���Lua�ű��е���������  
	cout << "arg1=" << arg1 << endl;
	cout << "arg2=" << arg2 << endl;

	//������printfѹ��ջ��  
	lua_getglobal(L, "printf");
	//����printf()����  
	lua_pcall(L, 0, 0, 0);

	//������sumѹ��ջ��  
	lua_getglobal(L, "sum");
	//�������  
	lua_pushinteger(L, 15);
	lua_pushinteger(L, 25);
	//����printf()����  
	lua_pcall(L, 2, 1, 0);//������2��������1������ֵ  
						  //�����ͽ��  
	cout << "sum=" << lua_tonumber(L, -1) << endl;

	//����tableѹ��ջ��  
	lua_getglobal(L, "table");
	//��ȡ��  
	//lua_pushnumber(L, 1);
	lua_pushstring(L, "b");
	lua_gettable(L, -2);
	//������е�һ��Ԫ��  
	cout << "table.a=" << lua_tonumber(L, -1) << endl;
}

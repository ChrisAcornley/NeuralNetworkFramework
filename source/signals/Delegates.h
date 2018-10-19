/////////////////////////////////////////////////////
//
//	Christopher Acornley - 2016
//	c.acornley@abertay.ac.uk
// 
/////////////////////////////////////////////////////

#ifndef CPPANN_DELEGATES_HPP
#define CPPANN_DELEGATES_HPP

#include <vector>
#include <functional>
#include <iostream>

namespace CPPANN
{
	using namespace std::placeholders;

	class Delegate
	{
	public:
		Delegate() : delegateId(0), functionId("") { }
		Delegate(const std::string& newStringId) : functionId(newStringId) { }
		const uintptr_t getContextId() const { return delegateId; }
		void setContextId(const uintptr_t newId) { delegateId = newId; }
		const std::string& getStringId() const { return functionId; }
		void setFunctionId(const std::string& newFuncId) { functionId = newFuncId; }
	private:
		uintptr_t delegateId;
		std::string functionId;
	};

	class Delegate0 : public Delegate
	{
	public:
		Delegate0(std::function<void()> callback)
		: Delegate(callback.target_type().name())
		, functionCall(callback)
		{
		}

		void Emit()
		{
			functionCall();
		}

	private:
		std::function<void()> functionCall;
	};

	template<class A> class Delegate1 : public Delegate
	{
	public:
		Delegate1(std::function<void(A)> callback)
		: Delegate(callback.target_type().name())
		, functionCall(callback)
		{
		}

		void Emit(A arg1)
		{
			functionCall(arg1);
		}

	private:
		std::function<void(A)> functionCall;
	};

	template<class A, class B> class Delegate2 : public Delegate
	{
	public:
		Delegate2(std::function<void(A, B)> callback)
		: Delegate(callback.target_type().name())
		, functionCall(callback)
		{
		}

		void Emit(A arg1, B arg2)
		{
			functionCall(arg1, arg2);
		}

	private:
		std::function<void(A, B)> functionCall;
	};

	template<typename A, typename B, typename C> class Delegate3 : public Delegate
	{
	public:
		Delegate3(std::function<void(A, B, C)> callback)
		: Delegate((int)callback.target_type().hash_code())
		, functionCall(callback)
		{
		}

		void Emit(A arg1, B arg2, C arg3)
		{
			functionCall(arg1, arg2, arg3);
		}

	private:
		std::function<void(A, B, C)> functionCall;
	};

	template<typename A, typename B, typename C, typename D> class Delegate4 : public Delegate
	{
	public:
		Delegate4(std::function<void(A, B, C, D)> callback)
		: Delegate((int)callback.target_type().hash_code())
		, functionCall(callback)
		{
		}

		void Emit(A arg1, B arg2, C arg3, D arg4)
		{
			functionCall(arg1, arg2, arg3, arg4);
		}

	private:
		std::function<void(A, B, C, D)> functionCall;
	};

	template<typename A, typename B, typename C, typename D, typename E> class Delegate5 : public Delegate
	{
	public:
		Delegate5(std::function<void(A, B, C, D, E)> callback)
		: Delegate((int)callback.target_type().hash_code())
		, functionCall(callback)
		{
		}

		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5)
		{
			functionCall(arg1, arg2, arg3, arg4, arg5);
		}

	private:
		std::function<void(A, B, C, D, E)> functionCall;
	};

	template<typename A, typename B, typename C, typename D, typename E, typename F> class Delegate6 : public Delegate
	{
	public:
		Delegate6(std::function<void(A, B, C, D, E, F)> callback)
		: Delegate((int)callback.target_type().hash_code())
		, functionCall(callback)
		{
		}

		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6)
		{
			functionCall(arg1, arg2, arg3, arg4, arg5, arg6);
		}

	private:
		std::function<void(A, B, C, D, E, F)> functionCall;
	};

	template<typename A, typename B, typename C, typename D, typename E, typename F, typename G> class Delegate7 : public Delegate
	{
	public:
		Delegate7(std::function<void(A, B, C, D, E, F, G)> callback)
		: Delegate((int)callback.target_type().hash_code())
		, functionCall(callback)
		{
		}

		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6, G arg7)
		{
			functionCall(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
		}

	private:
		std::function<void(A, B, C, D, E, F, G)> functionCall;
	};

	template<typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H> class Delegate8 : public Delegate
	{
	public:
		Delegate8(std::function<void(A, B, C, D, E, F, G, H)> callback)
		: Delegate((int)callback.target_type().hash_code())
		, functionCall(callback)
		{
		}

		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6, G arg7, H arg8)
		{
			functionCall(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
		}

	private:
		std::function<void(A, B, C, D, E, F, G, H)> functionCall;
	};

	template<typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I> class Delegate9 : public Delegate
	{
	public:
		Delegate9(std::function<void(A, B, C, D, E, F, G, H, I)> callback)
		: Delegate((int)callback.target_type().hash_code())
		, functionCall(callback)
		{
		}

		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6, G arg7, H arg8, I arg9)
		{
			functionCall(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
		}

	private:
		std::function<void(A, B, C, D, E, F, G, H, I)> functionCall;
	};

	template<class _Mem, class _Cxt> 
	Delegate0* MakeDelegate(void (_Mem::*func)(), _Cxt context)
	{
		Delegate0* del = new Delegate0(std::bind(func, context));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	template<class _Mem, class _Cxt, class _Arg1> 
	Delegate1<_Arg1>* MakeDelegate(void (_Mem::*func)(_Arg1 arg), _Cxt context)
	{
		Delegate1<_Arg1>* del = new Delegate1<_Arg1>(std::bind(func, context, _1));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	template<class _Mem, class _Cxt, class _Arg1, class _Arg2> 
	Delegate2<_Arg1, _Arg2>* MakeDelegate(void (_Mem::*func)(_Arg1 arg, _Arg2 arg2), _Cxt context)
	{
		Delegate2<_Arg1, _Arg2>* del = new Delegate2<_Arg1, _Arg2>(std::bind(func, context, _1, _2));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	template<class _Mem, class _Cxt, class _Arg1, class _Arg2, class _Arg3> 
	Delegate3<_Arg1, _Arg2, _Arg3>* MakeDelegate(void (_Mem::*func)(_Arg1 arg, _Arg2 arg2, _Arg3 arg3), _Cxt context)
	{
		Delegate3<_Arg1, _Arg2, _Arg3>* del = new Delegate3<_Arg1, _Arg2, _Arg3>(std::bind(func, context, _1, _2, _3));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	template<class _Mem, class _Cxt, class _Arg1, class _Arg2, class _Arg3, class _Arg4> 
	Delegate4<_Arg1, _Arg2, _Arg3, _Arg4>* MakeDelegate(void (_Mem::*func)(_Arg1 arg, _Arg2 arg2, _Arg3 arg3, _Arg4 arg4), _Cxt context)
	{
		Delegate4<_Arg1, _Arg2, _Arg3, _Arg4>* del = new Delegate4<_Arg1, _Arg2, _Arg3, _Arg4>(std::bind(func, context, _1, _2, _3, _4));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	template<class _Mem, class _Cxt, class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5> 
	Delegate5<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5>* MakeDelegate(void (_Mem::*func)(_Arg1 arg, _Arg2 arg2, _Arg3 arg3, _Arg4 arg4, _Arg5 arg5), _Cxt context)
	{
		Delegate5<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5>* del = new Delegate5<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(std::bind(func, context, _1, _2, _3, _4, _5));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	template<class _Mem, class _Cxt, class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6>
	Delegate6<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>* MakeDelegate(void (_Mem::*func)(_Arg1 arg, _Arg2 arg2, _Arg3 arg3, _Arg4 arg4, _Arg5 arg5, _Arg6 arg6), _Cxt context)
	{
		Delegate6<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>* del = new Delegate6<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(std::bind(func, context, _1, _2, _3, _4, _5, _6));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	template<class _Mem, class _Cxt, class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7>
	Delegate7<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>* MakeDelegate(void (_Mem::*func)(_Arg1 arg, _Arg2 arg2, _Arg3 arg3, _Arg4 arg4, _Arg5 arg5, _Arg6 arg6, _Arg7 arg7), _Cxt context)
	{
		Delegate7<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>* del = new Delegate7<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(std::bind(func, context, _1, _2, _3, _4, _5, _6, _7));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	template<class _Mem, class _Cxt, class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8>
	Delegate8<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>* MakeDelegate(void (_Mem::*func)(_Arg1 arg, _Arg2 arg2, _Arg3 arg3, _Arg4 arg4, _Arg5 arg5, _Arg6 arg6, _Arg7 arg7, _Arg8 arg8), _Cxt context)
	{
		Delegate8<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>* del = new Delegate8<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(std::bind(func, context, _1, _2, _3, _4, _5, _6, _7, _8));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	template<class _Mem, class _Cxt, class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8, class _Arg9>
	Delegate9<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>* MakeDelegate(void (_Mem::*func)(_Arg1 arg, _Arg2 arg2, _Arg3 arg3, _Arg4 arg4, _Arg5 arg5, _Arg6 arg6, _Arg7 arg7, _Arg8 arg8, _Arg9 arg9), _Cxt context)
	{
		Delegate9<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>* del = new Delegate9<_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(std::bind(func, context, _1, _2, _3, _4, _5, _6, _7, _8, _9));
		if (del)
		{
			del->setContextId((uintptr_t)context);
			return del;
		}

		return nullptr;
	}

	#define MAKE_DELEGATE(A, B) MakeDelegate(A, B)
}

#endif
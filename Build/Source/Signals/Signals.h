/////////////////////////////////////////////////////
//
//	Christopher Acornley - 2016
//	c.acornley@abertay.ac.uk
// 
/////////////////////////////////////////////////////

#ifndef CPPANN_SIGNALS_HPP
#define CPPANN_SIGNALS_HPP

#include <assert.h>
#include "Delegates.h"

namespace CPPANN
{
	template<class _DelType> void addDelegateToSignal(_DelType del, std::vector<_DelType>& delVector)
	{
		for (_DelType delObj : delVector)
		{
			if (delObj->getContextId() == del->getContextId())
			{
				if (delObj->getStringId() == del->getStringId())
				{
					delete del;
				}
				else
				{
					printf("Cannot add Delegate - Already connected to signal");
				}
			}
		}

		delVector.push_back(del);
	}

#define ADD_DELEGATE(A, B) addDelegateToSignal(A, B)

	template<typename _DelType> void removeDelegateFromSignal(_DelType del, std::vector<_DelType>& delVector)
	{
		auto itr = delVector.begin();
		for (itr; itr != delVector.end(); itr++)
		{
			if ((*itr)->getContextId() == del->getContextId())
			{
				if ((*itr)->getStringId() == del->getStringId())
				{
					break;
				}
			}
		}

		if (itr != delVector.end())
		{
			delete (*itr);
			delVector.erase(itr);
		}
		else
		{
			printf("Cannot remove Delegate - Not connected to Signal.");
		}

		delete del;
		del = nullptr;
	}

#define REMOVE_DELEGATE(A, B) removeDelegateFromSignal(A, B)

	template<class _DelType> class SignalBase
	{
	public:
		SignalBase()
			: broadcasting(false)
		{
		}

		~SignalBase()
		{
			for (auto callback : delegates)
			{
				delete callback;
			}

			delegates.clear();
		}

		void Connect(_DelType* connectDelegate)
		{
			if (!broadcasting)
			{
				ADD_DELEGATE(connectDelegate, delegates);
			}
			else
			{
				delegateToAdd.push_back(connectDelegate);
			}
		}

		void Disconnect(_DelType* removeDelegate)
		{
			if (!broadcasting)
			{
				REMOVE_DELEGATE(removeDelegate, delegates);
			}
			else
			{
				delegateToRemove.push_back(removeDelegate);
			}
		}

		void updateDelegateLists()
		{
			for (auto removeDelegate : delegateToRemove)
			{
				Disconnect(removeDelegate);
			}
			delegateToRemove.clear();

			for (auto newDelegate : delegateToAdd)
			{
				Connect(newDelegate);
			}
			delegateToAdd.clear();
		}

	protected:
		bool broadcasting; 
		std::vector<_DelType*> delegates;
		std::vector<_DelType*> delegateToRemove;
		std::vector<_DelType*> delegateToAdd;
	};

	class Signal0 : public SignalBase<Delegate0>
	{
	public:
		void Emit()
		{
			this->operator()();
		}

		void operator()()
		{
			broadcasting = true;

			for (auto callback : delegates)
			{
				callback->Emit();
			}

			broadcasting = false;

			updateDelegateLists();
		}
	};

    template<typename A> 
	class Signal1 : public SignalBase<Delegate1<A>>
	{
	public:
		void Emit(A arg1)
		{
			this->operator()(arg1);
		}

		void operator()(A arg1)
		{
			this->broadcasting = true;

			for (auto callback : this->delegates)
			{
				callback->Emit(arg1);
			}

			this->broadcasting = false;

			this->updateDelegateLists();
		}
	};

	template<typename A, typename B> 
	class Signal2 : public SignalBase<Delegate2<A, B>>
	{
	public:
		void Emit(A arg1, B arg2)
		{
			this->operator()(arg1, arg2);
		}

		void operator()(A arg1, B arg2)
		{
			this->broadcasting = true;

			for (auto callback : this->delegates)
			{
				callback->Emit(arg1, arg2);
			}

			this->broadcasting = false;

			this->updateDelegateLists();
		}
	};

	template<typename A, typename B, typename C> 
	class Signal3 : public SignalBase<Delegate3<A, B, C>>
	{
	public:
		void Emit(A arg1, B arg2, C arg3)
		{
			this->operator()(arg1, arg2, arg3);
		}

		void operator()(A arg1, B arg2, C arg3)
		{
			this->broadcasting = true;

			for (auto callback : this->delegates)
			{
				callback->Emit(arg1, arg2, arg3);
			}

			this->broadcasting = false;

			this->updateDelegateLists();
		}
	};

	template<typename A, typename B, typename C, typename D> 
	class Signal4 : public SignalBase<Delegate4<A, B, C, D>>
	{
	public:
		void Emit(A arg1, B arg2, C arg3, D arg4)
		{
			this->operator()(arg1, arg2, arg3, arg4);
		}

		void operator()(A arg1, B arg2, C arg3, D arg4)
		{
			this->broadcasting = true;

			for (auto callback : this->delegates)
			{
				callback->Emit(arg1, arg2, arg3, arg4);
			}

			this->broadcasting = false;

			this->updateDelegateLists();
		}
	};

	template<typename A, typename B, typename C, typename D, typename E> 
	class Signal5 : public SignalBase<Delegate5<A, B, C, D, E>>
	{
	public:
		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5)
		{
			this->operator()(arg1, arg2, arg3, arg4, arg5);
		}

		void operator()(A arg1, B arg2, C arg3, D arg4, E arg5)
		{
			this->broadcasting = true;

			for (auto callback : this->delegates)
			{
				callback->Emit(arg1, arg2, arg3, arg4, arg5);
			}

			this->broadcasting = false;

			this->updateDelegateLists();
		}
	};

	template<typename A, typename B, typename C, typename D, typename E, typename F> 
	class Signal6 : public SignalBase<Delegate6<A, B, C, D, E, F>>
	{
	public:
		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6)
		{
			this->operator()(arg1, arg2, arg3, arg4, arg5, arg6);
		}

		void operator()(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6)
		{
			this->broadcasting = true;

			for (auto callback : this->delegates)
			{
				callback->Emit(arg1, arg2, arg3, arg4, arg5, arg6);
			}

			this->broadcasting = false;

			this->updateDelegateLists();
		}
	};

	template<typename A, typename B, typename C, typename D, typename E, typename F, typename G> 
	class Signal7 : public SignalBase<Delegate7<A, B, C, D, E, F, G>>
	{
	public:
		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6, G arg7)
		{
			this->operator()(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
		}

		void operator()(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6, G arg7)
		{
			this->broadcasting = true;

			for (auto callback : this->delegates)
			{
				callback->Emit(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
			}

			this->broadcasting = false;

			this->updateDelegateLists();
		}
	};

	template<typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H> 
	class Signal8 : public SignalBase<Delegate8<A, B, C, D, E, F, G, H>>
	{
	public:
		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6, G arg7, H arg8)
		{
			this->operator()(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
		}

		void operator()(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6, G arg7, H arg8)
		{
			this->broadcasting = true;

			for (auto callback : this->delegates)
			{
				callback->Emit(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
			}

			this->broadcasting = false;

			this->updateDelegateLists();
		}
	};

	template<typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I> 
	class Signal9 : public SignalBase<Delegate9<A, B, C, D, E, F, G, H, I>>
	{
	public:
		void Emit(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6, G arg7, H arg8, I arg9)
		{
			this->operator()(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
		}

		void operator()(A arg1, B arg2, C arg3, D arg4, E arg5, F arg6, G arg7, H arg8, I arg9)
		{
			this->broadcasting = true;

			for (auto callback : this->delegates)
			{
				callback->Emit(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
			}

			this->broadcasting = false;

			this->updateDelegateLists();
		}
	};
}

#endif
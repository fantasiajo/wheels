#pragma once 

#include <memory>

template <typename T>
class Singleton {
public:
	Singleton() = delete;
	~Singleton() = delete;
	Singleton(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;
	Singleton& operator=(const Singleton &) = delete;
	Singleton& operator=(Singleton&&) = delete;

	template <typename... Args>
	static std::shared_ptr<T> instance(Args&&... args){
		std::call_once(flg,_instance<Args...>,std::forward<Args>(args)...);
		return pT;
	}

private:
	template <typename... Args>
	static void _instance(Args&&... args){
		pT = std::make_shared<T>(std::forward<Args>(args)...);
	}

	static std::shared_ptr<T> pT;
	static std::once_flag flg;
};


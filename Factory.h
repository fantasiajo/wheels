#pragma once

#include <memory>

template <typename T>
class Factory{
public:
	Factory() = delete;
	~Factory() = delete;
	Factory(const Factory &) = delete;
	Factory(Factory &&) = delete;
	Factory& operator=(const Factory &) = delete;
	Factory& operator=(Factory &&) = delete;

	template <typename... Args>
	static std::shared_ptr<T> instance(Args&&... args){
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template <typename F, typename... Args>
	static std::shared_ptr<T> instance(F&& f, Args&&... args){
		return f(args...);
	}
};

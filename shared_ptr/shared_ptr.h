#include <atomic>
#include <utility>
namespace LZ {
	template<typename T>
	class shared_ptr {
	public:
		shared_ptr(T* _pT)
			:pT(_pT),
			pCnt(new std::atomic<int>(1))
		{
		}
		shared_ptr(const shared_ptr &sptr)
			:pT(sptr.pT),
			pCnt(sptr.pCnt)
		{
			++*pCnt;
		}
		shared_ptr & operator =(const shared_ptr &sptr) {
			if (this != &sptr) {
				shared_ptr tmp(sptr);
				swap(tmp);
			}
			return *this;
		}
		~shared_ptr() {
			--*pCnt;
			if (!*pCnt) {
				delete pT;
				delete pCnt;
			}
		}

		void swap(shared_ptr &sptr) {
			using std::swap;
			swap(pT, sptr.pT);
			swap(pCnt, sptr.pCnt);
		}
		int getCnt() {
			return *pCnt;
		}
	private:
		T* pT;
		std::atomic<int> *pCnt;
	};
}

#pragma once
template <class T>
	class Array
	{
	private:
		T* m_pData;
		unsigned int m_nSize;
	public:
		Array(unsigned int nSize) : m_nSize(nSize)
		{
			if (m_nSize > 0)	//Cannot create empty array, passing 0 would result in initialized pointer
			{
				m_pData = new (std::nothrow) T[m_nSize];	//bug #1. no way to check if allocation has succeeded
			}
		}
		virtual ~Array()
		{
			if (m_pData != NULL)	//usage of nullptr is recommended, could ommit if clause
			{
				delete m_pData;	//Bug #3. Should be delete[], using delete without [] causes behaviour undefined
			}
		}
		bool Set(unsigned int nPos, const T& value)
		{
			if (nPos < m_nSize)
			{
				m_pData[nPos] = value;
				return true;
			}
			else
			{
				return false;
			}
		}
		T Get(unsigned int nPos)
		{
			if (nPos < m_nSize)
			{
				return m_pData[nPos];
			}
			else
			{
				return T();	/* Bug #2. will return 0 which might me confusing, 
							when array contains value 0, should throw std::out of range*/
			}
		}
		const T* getPointer(void) const
		{
			/*defined only for test purposes*/
			return m_pData;
		}
		T* getPointer(void)
		{
			return m_pData;
		}
	};


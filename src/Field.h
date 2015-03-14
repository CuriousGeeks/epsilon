#pragma once

namespace el{

class CField
{
public:	
	enum enmFieldTypeId
	{
		eInvalid = 0,
		eBool,
		eChar,
		eShort,
		eInt,
		eUInt,
		eUShort,
		eUChar,
		eFloat,
		eDouble,
		eString,
		eDate
	};
	
	CField(int nColumnId) { m_nColumnId = nColumnId; }
	
	virtual int  GetTypeId() { return eInvalid;}
	
	inline int  GetColumnId() { return m_nColumnId; }
	inline void SetColumnId(int nColumnId) { m_nColumnId = nColumnId; }
	
	//int Get() { return GetAddress(}
private:
	int m_nColumnId;	
};




class CFieldInt : public CField
{
public:	
	enum enmTypeId
	{
		eTypeId = eInt
	};
	
	CFieldInt (int nId) : CField(nId) {}
	
	inline  int  GetTypeId() { return eTypeId;}
	inline  bool Get() { return m_iVal;}
	
private:
	int m_iVal;
};

class CFieldUInt : public CField
{
public:	
	enum enmTypeId
	{
		eTypeId = eUInt
	};
	
	CFieldUInt (int nId) : CField(nId) {}
	
	inline int  GetTypeId() { return eTypeId;}
	inline unsigned int Get() { return m_nVal;}
	
private:
	unsigned int m_nVal;
};



class CFieldBool : public CField
{
public:	
	enum enmTypeId
	{
		eTypeId = eBool
	};
	
	CFieldBool(int nId) : CField(nId) {}
	
	inline int  GetTypeId() { return eTypeId;}
	inline bool Get() { return m_bVal;}
	
private:
	int m_bVal;	
};


class CFieldChar : public CField
{
public:	
	enum enmTypeId
	{
		eTypeId = eChar
	};
	
	CFieldChar(int nId) : CField(nId) {}
	
	inline int  GetTypeId() { return eTypeId;}
	inline char Get() { return m_chVal;}
	
private:
	char m_chVal;	
};

class CFieldDate : public CField
{
public:	
	enum enmTypeId
	{
		eTypeId = eDate
	};
	
	CFieldDate(int nId) : CField(nId) {}
	
	inline int  GetTypeId() { return eTypeId;}
	inline char Get() { return m_chVal;}
	
private:
	char m_chVal;	
};

class CFieldString : public CField
{
public:
		
	enum enmTypeId
	{
		eTypeId = eString
	};
		
			
	CFieldString(int nId, int nSize = 0) : CField(nId) 
	{
		m_chVal = (nSize > 0 ? new char[nSize] : nullptr);
	}
	
	~CFieldString()
	{
		if (m_chVal != nullptr)
			delete m_chVal;
	}
	
	inline int  GetTypeId() { return eTypeId;}
	inline char *Get() { return m_chVal;}
	
private:
	char *m_chVal;	
};


};
#pragma once

#include<string>

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
	
	virtual void SetValue(const std::string& sValue) {}
	virtual void GetValue(std::string& sValue) {}

	virtual bool IsNull(){ return false; }
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
	inline  int Get() { return m_iVal;}
	inline bool IsNull() { return m_bIsNull; }
	void SetValue(const std::string& sValue);
	
private:
	int m_iVal;
	bool m_bIsNull = false;
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
	inline bool IsNull() { return m_bIsNull; }
	
	void SetValue(const std::string& sValue);
private:
	unsigned int m_nVal;
	bool m_bIsNull = false;
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
	inline bool IsNull() { return m_bIsNull; }

	void SetValue(const std::string& sValue);
private:
	bool m_bVal;	
	bool m_bIsNull = false;
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
	inline bool IsNull() { return m_bIsNull; }

	void SetValue(const std::string& sValue);
private:
	char m_chVal;	
	bool m_bIsNull = false;
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
	inline time_t Get() { return m_chVal;}
	inline bool IsNull() { return m_bIsNull; } 

	void SetValue(const std::string& sValue);
private:
	time_t m_chVal;	
	bool m_bIsNull = false;
};

class CFieldString : public CField
{
public:
		
	enum enmTypeId
	{
		eTypeId = eString
	};
		
			
	CFieldString(int nId) : CField(nId) 
	{
		m_strVal = "";
	}
	
	~CFieldString()
	{
	}
	
	inline int  GetTypeId() { return eTypeId;}
	inline std::string& Get() { return m_strVal;}
	inline bool IsNull() { return m_bIsNull; }
	
	void SetValue(const std::string& sValue);
private:
	std::string m_strVal;	
	bool m_bIsNull = false;
};

class CFieldFloat : public CField
{
public:
	enum enmTypeId
	{
		eTypeId = eFloat
	};

	CFieldFloat(float nId) : CField(nId) {}

	inline  int  GetTypeId() { return eTypeId; }
	inline  float Get() { return m_fVal; }
	inline bool IsNull() { return m_bIsNull; }

	void SetValue(const std::string& sValue);
private:
	float m_fVal;
	bool m_bIsNull = false;
};

class CFieldDouble : public CField
{
public:
	enum enmTypeId
	{
		eTypeId = eInt
	};

	CFieldDouble(double nId) : CField(nId) {}

	inline  int  GetTypeId() { return eTypeId; }
	inline  double Get() { return m_dVal; }
	inline bool IsNull() { return m_bIsNull; }

	void SetValue(const std::string& sValue);
private:
	double m_dVal;
	bool m_bIsNull = false;
};
};
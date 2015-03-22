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
	
	void SetValue(const std::string& sValue);
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
	
	void SetValue(const std::string& sValue);
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
	
	void SetValue(const std::string& sValue);
private:
	bool m_bVal;	
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
	
	void SetValue(const std::string& sValue);
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
	inline time_t Get() { return m_chVal;}
	
	void SetValue(const std::string& sValue);
private:
	time_t m_chVal;	
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
	
	void SetValue(const std::string& sValue);
private:
	std::string m_strVal;	
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

	void SetValue(const std::string& sValue);
private:
	float m_fVal;
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

	void SetValue(const std::string& sValue);
private:
	double m_dVal;
};
};
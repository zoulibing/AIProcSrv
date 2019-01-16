/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef test_TYPES_H
#define test_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace rock {

class Request;

class ResultItem;

class Respone;

typedef struct _Request__isset {
  _Request__isset() : camID(false), serialID(false), width(false), height(false), pic_nums(false), pic_per_size(false), buff(false) {}
  bool camID :1;
  bool serialID :1;
  bool width :1;
  bool height :1;
  bool pic_nums :1;
  bool pic_per_size :1;
  bool buff :1;
} _Request__isset;

class Request : public virtual ::apache::thrift::TBase {
 public:

  Request(const Request&);
  Request& operator=(const Request&);
  Request() : camID(0), serialID(0), width(0), height(0), pic_nums(0), pic_per_size(0), buff() {
  }

  virtual ~Request() throw();
  int32_t camID;
  int32_t serialID;
  int32_t width;
  int32_t height;
  int32_t pic_nums;
  int32_t pic_per_size;
  std::string buff;

  _Request__isset __isset;

  void __set_camID(const int32_t val);

  void __set_serialID(const int32_t val);

  void __set_width(const int32_t val);

  void __set_height(const int32_t val);

  void __set_pic_nums(const int32_t val);

  void __set_pic_per_size(const int32_t val);

  void __set_buff(const std::string& val);

  bool operator == (const Request & rhs) const
  {
    if (!(camID == rhs.camID))
      return false;
    if (!(serialID == rhs.serialID))
      return false;
    if (!(width == rhs.width))
      return false;
    if (!(height == rhs.height))
      return false;
    if (!(pic_nums == rhs.pic_nums))
      return false;
    if (!(pic_per_size == rhs.pic_per_size))
      return false;
    if (!(buff == rhs.buff))
      return false;
    return true;
  }
  bool operator != (const Request &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Request & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Request &a, Request &b);

inline std::ostream& operator<<(std::ostream& out, const Request& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _ResultItem__isset {
  _ResultItem__isset() : name(false), id(false), x0(false), y0(false), x1(false), y1(false) {}
  bool name :1;
  bool id :1;
  bool x0 :1;
  bool y0 :1;
  bool x1 :1;
  bool y1 :1;
} _ResultItem__isset;

class ResultItem : public virtual ::apache::thrift::TBase {
 public:

  ResultItem(const ResultItem&);
  ResultItem& operator=(const ResultItem&);
  ResultItem() : name(), id(0), x0(0), y0(0), x1(0), y1(0) {
  }

  virtual ~ResultItem() throw();
  std::string name;
  int32_t id;
  int32_t x0;
  int32_t y0;
  int32_t x1;
  int32_t y1;

  _ResultItem__isset __isset;

  void __set_name(const std::string& val);

  void __set_id(const int32_t val);

  void __set_x0(const int32_t val);

  void __set_y0(const int32_t val);

  void __set_x1(const int32_t val);

  void __set_y1(const int32_t val);

  bool operator == (const ResultItem & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(id == rhs.id))
      return false;
    if (!(x0 == rhs.x0))
      return false;
    if (!(y0 == rhs.y0))
      return false;
    if (!(x1 == rhs.x1))
      return false;
    if (!(y1 == rhs.y1))
      return false;
    return true;
  }
  bool operator != (const ResultItem &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ResultItem & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ResultItem &a, ResultItem &b);

inline std::ostream& operator<<(std::ostream& out, const ResultItem& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _Respone__isset {
  _Respone__isset() : cameID(false), serialID(false), ritems(false) {}
  bool cameID :1;
  bool serialID :1;
  bool ritems :1;
} _Respone__isset;

class Respone : public virtual ::apache::thrift::TBase {
 public:

  Respone(const Respone&);
  Respone& operator=(const Respone&);
  Respone() : cameID(0), serialID(0) {
  }

  virtual ~Respone() throw();
  int32_t cameID;
  int32_t serialID;
  std::vector<ResultItem>  ritems;

  _Respone__isset __isset;

  void __set_cameID(const int32_t val);

  void __set_serialID(const int32_t val);

  void __set_ritems(const std::vector<ResultItem> & val);

  bool operator == (const Respone & rhs) const
  {
    if (!(cameID == rhs.cameID))
      return false;
    if (!(serialID == rhs.serialID))
      return false;
    if (!(ritems == rhs.ritems))
      return false;
    return true;
  }
  bool operator != (const Respone &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Respone & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Respone &a, Respone &b);

inline std::ostream& operator<<(std::ostream& out, const Respone& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
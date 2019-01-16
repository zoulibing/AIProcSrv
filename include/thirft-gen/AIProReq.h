/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef AIProReq_H
#define AIProReq_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "test_types.h"

namespace rock {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class AIProReqIf {
 public:
  virtual ~AIProReqIf() {}
  virtual void sendImage(Respone& _return, const int32_t camID, const int32_t seraNO, const Request& req) = 0;
};

class AIProReqIfFactory {
 public:
  typedef AIProReqIf Handler;

  virtual ~AIProReqIfFactory() {}

  virtual AIProReqIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(AIProReqIf* /* handler */) = 0;
};

class AIProReqIfSingletonFactory : virtual public AIProReqIfFactory {
 public:
  AIProReqIfSingletonFactory(const boost::shared_ptr<AIProReqIf>& iface) : iface_(iface) {}
  virtual ~AIProReqIfSingletonFactory() {}

  virtual AIProReqIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(AIProReqIf* /* handler */) {}

 protected:
  boost::shared_ptr<AIProReqIf> iface_;
};

class AIProReqNull : virtual public AIProReqIf {
 public:
  virtual ~AIProReqNull() {}
  void sendImage(Respone& /* _return */, const int32_t /* camID */, const int32_t /* seraNO */, const Request& /* req */) {
    return;
  }
};

typedef struct _AIProReq_sendImage_args__isset {
  _AIProReq_sendImage_args__isset() : camID(false), seraNO(false), req(false) {}
  bool camID :1;
  bool seraNO :1;
  bool req :1;
} _AIProReq_sendImage_args__isset;

class AIProReq_sendImage_args {
 public:

  AIProReq_sendImage_args(const AIProReq_sendImage_args&);
  AIProReq_sendImage_args& operator=(const AIProReq_sendImage_args&);
  AIProReq_sendImage_args() : camID(0), seraNO(0) {
  }

  virtual ~AIProReq_sendImage_args() throw();
  int32_t camID;
  int32_t seraNO;
  Request req;

  _AIProReq_sendImage_args__isset __isset;

  void __set_camID(const int32_t val);

  void __set_seraNO(const int32_t val);

  void __set_req(const Request& val);

  bool operator == (const AIProReq_sendImage_args & rhs) const
  {
    if (!(camID == rhs.camID))
      return false;
    if (!(seraNO == rhs.seraNO))
      return false;
    if (!(req == rhs.req))
      return false;
    return true;
  }
  bool operator != (const AIProReq_sendImage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AIProReq_sendImage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AIProReq_sendImage_pargs {
 public:


  virtual ~AIProReq_sendImage_pargs() throw();
  const int32_t* camID;
  const int32_t* seraNO;
  const Request* req;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AIProReq_sendImage_result__isset {
  _AIProReq_sendImage_result__isset() : success(false) {}
  bool success :1;
} _AIProReq_sendImage_result__isset;

class AIProReq_sendImage_result {
 public:

  AIProReq_sendImage_result(const AIProReq_sendImage_result&);
  AIProReq_sendImage_result& operator=(const AIProReq_sendImage_result&);
  AIProReq_sendImage_result() {
  }

  virtual ~AIProReq_sendImage_result() throw();
  Respone success;

  _AIProReq_sendImage_result__isset __isset;

  void __set_success(const Respone& val);

  bool operator == (const AIProReq_sendImage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AIProReq_sendImage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AIProReq_sendImage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AIProReq_sendImage_presult__isset {
  _AIProReq_sendImage_presult__isset() : success(false) {}
  bool success :1;
} _AIProReq_sendImage_presult__isset;

class AIProReq_sendImage_presult {
 public:


  virtual ~AIProReq_sendImage_presult() throw();
  Respone* success;

  _AIProReq_sendImage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class AIProReqClient : virtual public AIProReqIf {
 public:
  AIProReqClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  AIProReqClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void sendImage(Respone& _return, const int32_t camID, const int32_t seraNO, const Request& req);
  void send_sendImage(const int32_t camID, const int32_t seraNO, const Request& req);
  void recv_sendImage(Respone& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class AIProReqProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<AIProReqIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (AIProReqProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_sendImage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  AIProReqProcessor(boost::shared_ptr<AIProReqIf> iface) :
    iface_(iface) {
    processMap_["sendImage"] = &AIProReqProcessor::process_sendImage;
  }

  virtual ~AIProReqProcessor() {}
};

class AIProReqProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  AIProReqProcessorFactory(const ::boost::shared_ptr< AIProReqIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< AIProReqIfFactory > handlerFactory_;
};

class AIProReqMultiface : virtual public AIProReqIf {
 public:
  AIProReqMultiface(std::vector<boost::shared_ptr<AIProReqIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~AIProReqMultiface() {}
 protected:
  std::vector<boost::shared_ptr<AIProReqIf> > ifaces_;
  AIProReqMultiface() {}
  void add(boost::shared_ptr<AIProReqIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void sendImage(Respone& _return, const int32_t camID, const int32_t seraNO, const Request& req) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendImage(_return, camID, seraNO, req);
    }
    ifaces_[i]->sendImage(_return, camID, seraNO, req);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class AIProReqConcurrentClient : virtual public AIProReqIf {
 public:
  AIProReqConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  AIProReqConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void sendImage(Respone& _return, const int32_t camID, const int32_t seraNO, const Request& req);
  int32_t send_sendImage(const int32_t camID, const int32_t seraNO, const Request& req);
  void recv_sendImage(Respone& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
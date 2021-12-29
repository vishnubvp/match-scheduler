//
//  TypeDefs.h
//  MatchScheduler
//
//  Created by Vishnu Balasubramanian on 29/12/21.
//

#include <vector>
#include <map>
#include <list>


#ifndef TypeDefs_h
#define TypeDefs_h

#define SMART_PTR std

#define GLB_SMART_PTR_DEF(NAME)                                        \
    typedef SMART_PTR::shared_ptr<NAME> NAME##Ptr;                    \
    typedef SMART_PTR::weak_ptr<NAME>   NAME##WPtr;                    \
    typedef SMART_PTR::unique_ptr<NAME> NAME##UPtr;                    \


#define GLB_SMART_VEC_PTR_DEF(NAME)                                 \
    typedef std::vector< SMART_PTR::shared_ptr<NAME> > NAME##VPtr;  \
    typedef SMART_PTR::shared_ptr< NAME##VPtr > NAME##PVPtr;        \

#define FORWARD_DECLARE(NAME) \
    class NAME;\
    GLB_SMART_PTR_DEF(NAME)\
    GLB_SMART_VEC_PTR_DEF(NAME)

#endif /* TypeDefs_h */

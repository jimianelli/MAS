/* 
 * File:   Object.hpp
 * Author: Matthew
 *
 * Created on March 2, 2015, 10:16 AM
 */

#ifndef OBJECT_HPP
#define	OBJECT_HPP

#include <string>


namespace mas {

    template<typename REAL_T, typename EVAL_T>
    class Information;
    
    /**
     * Base class for MAS objects.
     */
    class Object {
   
    public:

        
        
        virtual std::string ToString() const{
            return "Function named \"ToString()\", Not yet implemented!";
        }
        
  
        friend std::ostream& operator<<(std::ostream& os, const Object& obj) {
            os<<obj.ToString();
            return os;
        }
    };
    
    
    
    /**
     * Base class for MAS evaluation objects.
     */
    template<typename REAL_T, typename EVAL_T>
    class EvaluationObject: public Object{
        Information<REAL_T,EVAL_T>* info;
    public:
        Information<REAL_T, EVAL_T>* GetInfo() const {
            return info;
        }

        void SetInfo(Information<REAL_T, EVAL_T>* info) {
            this->info = info;
        }
        
        /**
         * Initialize from a Information object.
         * @param info
         */
        virtual void Initialize(Information<REAL_T, EVAL_T>* info) {
            this->info = info;
        }
        

    };
    
    
}


#endif	/* OBJECT_HPP */


// THIS IS A GENERATED FILE - DO NOT EDIT
#define FG
#define PNSGA
#define DIV
#line 1 "/home/hmengist/sferes/sferes2/trunk/exp/modularity/cascadeand.cpp"
 //#define NO_PARALLEL
#include <iostream>
#include <bitset>
#include <boost/assign/list_of.hpp>
#include <sferes/phen/parameters.hpp>
#include <sferes/gen/evo_float.hpp>
#include <sferes/gen/sampled.hpp>

#include <sferes/ea/nsga2.hpp>
#include <sferes/eval/eval.hpp>
#include <sferes/stat/pareto_front.hpp>
#include <sferes/modif/dummy.hpp>
#include <sferes/run.hpp>
#include <modules/nn2/nn.hpp>
#include <modules/nn2/gen_dnn_ff.hpp>
#include <modules/nn2/phen_dnn.hpp>
#include <modules/modularity/modularity.hpp>
#include <modules/modularity/hierarchy.hpp>
#include<string>
#include <iostream>
#include "behavior_div.hpp"
 //#include "behavior_nov.hpp"
#ifdef PNSGA
 #include "pnsga.hpp"
#endif

#ifdef NOVMAP
 # include "modif_novmap.hpp"
#endif


#include "gen_spatial.hpp"
#include "stat_modularity.hpp"
#include "mvg.hpp"

using namespace sferes;
using namespace nn;
using namespace sferes::gen::evo_float;
using namespace sferes::gen::dnn;

#include <boost/algorithm/string.hpp>

#define SFERES_PARAMS(P)                                                    \
  struct Ps__ { Ps__() {                                                    \
                  static std::string __params = # P;                        \
                  boost::replace_all(__params, ";", ";\n");                 \
                  boost::replace_all(__params, "{", "{\n");                 \
                  boost::replace_all(__params, "static const", "");         \
                  std::cout << "Parameters:" << __params << std::endl; } }; \
  P;                                                                        \
  static Ps__ ____p;

SFERES_PARAMS(
  struct Params
  {
    static long int seed;
    struct pop
    {
      static const unsigned size = 1000;
       //static const unsigned nb_gen = 5001;
#ifdef NOVMAP
      static const unsigned nb_gen = 100001;
#else
      static const unsigned nb_gen = 25001;
#endif
      static const int dump_period = nb_gen - 1;
      static const int initial_aleat = 1;

    };
    struct ea
    {
#ifdef PR10
      SFERES_ARRAY(float, obj_pressure, 1.0, 0.1, 1.0);
#elif defined(PR25)
      SFERES_ARRAY(float, obj_pressure, 1.0, 0.25, 1.0);
#elif defined(PR50)
      SFERES_ARRAY(float, obj_pressure, 1.0, 0.5, 1.0);
#elif defined(PR100)
      SFERES_ARRAY(float, obj_pressure, 1.0, 1.0, 1.0);
#else
      SFERES_ARRAY(float, obj_pressure, 1.0, 1.0, 1.0);
#endif
    };
    struct rand_obj
    {
      static const float std_dev = 0.1;
    };
    struct dnn
    {
      struct bias
      {
        struct evo_float
        {
          static const float cross_rate = 0.5f;
          static const float mutation_rate = 1.0 / 20.0f;
          static const float eta_m = 10.0f;
          static const float eta_c = 10.0f;
          static const mutation_t mutation_type = polynomial;
          static const cross_over_t cross_over_type = sbx;
        };
        struct sampled
        {
          SFERES_ARRAY(float, values, -2, -1, 0, 1, 2);
          static const float mutation_rate = 1.0 / 15.0f;
          static const float cross_rate = 0.5f;
          static const bool ordered = true;
        };
      };
      struct weight
      {
        struct sampled
        {
          SFERES_ARRAY(float, values, -2, -1, 1, 2);
          static const float mutation_rate = 1.0f;
          static const float cross_rate = 0.5f;
          static const bool ordered = true;
        };
        struct evo_float
        {
          static const float cross_rate = 0.5f;
          static const float mutation_rate = 1.0f;
          static const float eta_m = 10.0f;
          static const float eta_c = 10.0f;
          static const mutation_t mutation_type = polynomial;
          static const cross_over_t cross_over_type = sbx;
        };
      };


      static const size_t nb_outputs = 1;
      static const size_t nb_inputs = 8;

      static const size_t min_nb_neurons = 10; //useless
      static const size_t max_nb_neurons = 30; //useless

      static const size_t min_nb_conns = 20;
      static const size_t max_nb_conns = 100; //nb_outputs * 10;

      static const float m_rate_add_conn = 0.2f;
      static const float m_rate_del_conn = 0.2f;

      static const float m_rate_change_conn = 0.0f;
      static const float m_rate_add_neuron = 0.05f;
      static const float m_rate_del_neuron = 0.05f;
      static const float m_avg_weight = 2.0f;

      static const int io_param_evolving = true;
      static const init_t init = ff;
      struct spatial
      {
        SFERES_ARRAY(int, layers,8, 7, 6, 5, 4, 3, 2, 1);
        SFERES_ARRAY(float, x,
                    -3.5,-2.5, -1.5, -0.5, 0.5, 1.5, 2.5, 3.5,
                    -3,-1.5, -0.5, 0.5, 1.5, 2.5, 3.5,
                    -2.0, -0.5, 0.5, 1.5, 2.5, 3.5,
                    1.0, 0.5, 1.5, 2.5, 3.5,
		    0.0, 1.5, 2.5, 3.5,
 	            1.0, 2.5, 3.5,
		    2.0, 3.5,
		    3.0			
       );
        SFERES_ARRAY(float, y,
                     0, 0, 0, 0, 0, 0, 0, 0,
                     1, 1, 1, 1, 1, 1, 1,
                     2, 2, 2, 2, 2, 2,
                     3, 3, 3, 3, 3,
                     4, 4, 4, 4,
		     5, 5, 5,
                     6, 6,
                     7);
        SFERES_ARRAY(float, z,
                     0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0,
		     0, 0, 0, 0, 0,
		     0, 0, 0, 0,
		     0, 0, 0,
	             0, 0,
                     2);
        static const float min_coord = -6.0f;
        static const float max_coord = 6.0f;
#ifdef RANDCOORDS
        static const bool rand_coords = true;
#else
        static const bool rand_coords = false;
#endif
      };
    };

    struct parameters
    {
       // maximum value of parameters (weights & bias)
      static const float min = 0;
       // minimum value
      static const float max = 1;
    };
    struct stats
    {
      static const size_t period = 1;
    };
    struct fitness
    {
      static const size_t b_size = 256 * Params::dnn::nb_outputs;
    };
  };
  ) // end of params



// -1 to +1 sigmoid
namespace nn
{
  template<typename P>
  struct AfTanhNxor : public Af<P>
  {
    typedef P params_t;
    static const float lambda = 20.0f;
    AfTanhNxor() {
      assert(trait<P>::size(this->_params) == 1);
    }
    float operator() (float p) const
    {
      return tanh(lambda * (p + trait<P>::single_value(this->_params)));
    }
  };
}
bool sort_pred (std::pair<bool,int> left, std::pair<bool,int> right)
    {
        return left.second > right.second;
    }


SFERES_FITNESS(FitXorXor, sferes::fit::Fitness)
{
  public:
    FitXorXor()  {
    }

    template<typename Indiv>
    float dist(const Indiv& o) const
    {
      return (o.fit()._behavior ^ _behavior).count() / (float) _behavior.size();
    }

     // size of the behavior vector
    static const size_t b_size = Params::fitness::b_size;
    typedef std::bitset<b_size> behavior_t;

    template<typename Indiv>
    void eval(Indiv& ind)
    {
      std::vector<float> inputs(Params::dnn::nb_inputs);
      int k = (int)pow(2, Params::dnn::nb_inputs);
      float err1 = 0, err2 = 0, nba = 0;
      for (size_t s = 0; s < k; ++s)
      {
         // set inputs
        std::bitset<Params::dnn::nb_inputs> in(s);
        for (size_t i = 0; i < in.size(); ++i)
          inputs[i] = in[i] ? 1 : -1;
         // step
        for (size_t i = 0; i < ind.gen().get_depth(); ++i)
          ind.nn().step(inputs);
         // behaviors
        std::vector<bool> and_res;
        and_res.push_back(((bool)(inputs[0] > 0)) && ((bool)(inputs[1] > 0)));

        for (size_t i = 2; i < Params::dnn::nb_inputs-1; i +=1)
          and_res.push_back(and_res[i-2] && ((bool)(inputs[i] > 0)));
        for (size_t i = 0; i < Params::dnn::nb_outputs; ++i)
          _behavior[s * Params::dnn::nb_outputs + i] = ind.nn().get_outf(i) > 0 ? 1 : 0;
         // errors

        if (and_res[Params::dnn::nb_inputs-3] && inputs[Params::dnn::nb_inputs-1])

          err1 += ind.nn().get_outf(0) > 0 ? 0 : 1;
        else
          err1 += ind.nn().get_outf(0) > 0 ? 1 : 0;
       /* if (and_res[2] ^ and_res[3])
          err1 += ind.nn().get_outf(1) > 0 ? 0 : 1;
        else
          err1 += ind.nn().get_outf(1) > 0 ? 1 : 0;*/

      }
      this->_objs.clear();

#ifdef MVG
      this->_objs.push_back(-42); // this will be set later
#endif
      float norm = k * Params::dnn::nb_outputs;
      this->_values.resize(2);
      this->_values[0] = 1 - err1 / norm;
      //is->_values[1] = 1 - err2 / norm;

#ifdef FG
      this->_objs.push_back(1 - err1 / norm);
#endif
      this->_value = 1 - err1 / norm;

      typename Indiv::nn_t::graph_t gsimp =ind.gen().simplified_nn().get_graph();
      
     if (boost::num_edges(gsimp) == 0 || boost::num_vertices(gsimp) == 0)
       {
        _mod = 0.0;
        _grc = 0.0;
       }
   else
   {
        _mod = mod::modularity(gsimp);
	_grc = hierar::Get_GRC(gsimp);
   }

#ifdef MOD
      this->_objs.push_back(_mod);
#endif
#ifdef HE
      this->_objs.push_back(_grc);
#endif

       // length
      _length = ind.gen().compute_length();

#ifdef MAX_LENGTH
      this->_objs.push_back(-ind.gen().max_length());
#endif



      this->_nb_conns = boost::num_edges(gsimp);
#ifdef NCONNS
      this->_objs.push_back(-(int)boost::num_edges(gsimp));
#endif
      
      this->_nb_nodes = boost::num_vertices(gsimp);
#ifdef NNODES
      this->_objs.push_back(-(int)boost::num_vertices(gsimp));
#endif

#ifdef NCNODES
      this->_objs.push_back(-(int)boost::num_edges(gsimp) - (int)boost::num_vertices(gsimp));
#endif


#if defined(LENGTH) && !defined(ONP)
      this->_objs.push_back(-_length);
#endif

      // optimal length
      bool write_svg = (this->mode() == fit::mode::view);
      std::string fname="/project/evolutionaryRobotics/hmengist/7.25/test/ands/PH100/log/nn"+_postFix+".svg";
     _optlength = ind.gen().compute_optimal_length(0, write_svg,fname);
     //_optlength=_length;
#if defined(LENGTH) && defined(ONP)
      this->_objs.push_back(-_optlength);
#endif

#ifdef TLENGTH
      this->_objs.push_back(-ind.gen().compute_length(1.5)); //default
#endif


#if defined(DIV) || defined(NOV) || defined(NOVMAP)
      this->_objs.push_back(0);
#endif


#ifdef RANDOBJ
      this->_objs.push_back(rand() / (float)RAND_MAX);
#endif

      if (this->mode() == fit::mode::view)
      {
       recording(ind);
        //std::cout << "behavior:" << _behavior << std::endl;
        //std::ofstream ofs("/project/evolutionaryRobotics/hmengist/7.25/test/ands/PH100/log/nn"+_postFix+".dot");
                            
        //ind.nn().write(ofs);
        std::cout << "- FIT:" << 1 - err1 / norm << std::endl;
        std::cout << "- MOD:" << _mod << std::endl;
        std::cout << "- GRC:" << _grc << std::endl;
        std::cout << "length:" << _length << std::endl;
        std::cout << "nb neurons:" << ind.nn().get_nb_neurons() << std::endl;
         // dump in nn.svg
       //std::ofstream ofs2("/project/evolutionaryRobotics/hmengist/20130409hierar1/PCC/PAH50/nn"+_postFix+".svg");
       //ind.gen().write_svg(ofs2);
      
       //currentoutput(ind);
     }
       //bool write_svg = (this->mode() == fit::mode::view);
       //std::string fname="/project/evolutionaryRobotics/hmengist/7.25/allands/PCC25/nn"+_postFix+".svg";
      // _optlength = ind.gen().compute_optimal_length(0, write_svg,fname);

   }
    void set_value(float v) { this->_value = v; }
    float values(size_t k) const { return _values[k]; }
    size_t nb_values() const { return _values.size(); }
    const behavior_t& behavior() const { return _behavior; }
    float mod() const { return _mod; }
    float length() const { return _length; }
    float optlength() const { return _optlength; }
    int nb_conns() const { return _nb_conns; }
    int nb_nodes() const { return _nb_nodes; }
    double get_grc() const { return _grc;}
    void setPostFix(std::string postFix){_postFix = postFix;}
  protected:
    std::vector<float> _values;
    behavior_t _behavior;
    float _mod;
    float _length, _optlength;
    int _nb_nodes, _nb_conns;
    double _grc;
    std::string _postFix;

void ans_subproblem(std::vector<float> inputs,std::vector<bool>& and_res)
  {
    
      and_res.push_back(((bool)(inputs[0] > 0)) && ((bool)(inputs[1] > 0)));
      for (size_t i = 2; i < Params::dnn::nb_inputs-1; i +=1)
          and_res.push_back(and_res[i-2] && ((bool)(inputs[i] > 0)));
      and_res.push_back(and_res[Params::dnn::nb_inputs-3] && inputs[Params::dnn::nb_inputs-1]);
    
  }
template<typename I>
void non(I& indiv)
{
   typename I::nn_t::graph_t gsimp =indiv.gen().get_graph();
   BGL_FORALL_VERTICES_T(v, gsimp, typename I::nn_t::graph_t)
      {
        if (!gsimp[v].is_input()&&!gsimp[v].is_output())
         cout<<gsimp[v].get_id()<<endl;
      }
}
template<typename I>
void recording (I& indiv )
{
  float number_problems = 6.0;
  std::vector<int> output(indiv.nn().get_nb_neurons());
  std::vector<bool> xorand_res;
  std::vector<std::pair<bool,int>> threshold;
  std::pair<bool,int> values;
  std::vector<float> inputs(8);
  std::set<std::pair<int,string>> results;
  std::set<std::pair<int,string>>::iterator it;
  std::set<std::pair<bool,int>>::iterator ith;
  std::pair<std::set<std::pair<int,int>>::iterator,bool> ret;
  typename I::nn_t::graph_t gsimp =indiv.nn().get_graph();

  std::fstream deb;
cout<<"this is the  depth : "<<indiv.gen().get_depth()<<endl;
 for (int t = 0; t < 7; t++)
 {
    BGL_FORALL_VERTICES_T(v, indiv.nn().get_graph(), typename I::nn_t::graph_t)
  {
    if (!indiv.nn().get_graph()[v].is_input())
   {
     for (size_t s = 0; s < 256; ++s)
       {
        std::bitset<8> in(s);
        for (size_t i = 0; i < in.size(); ++i)
               inputs[i] = in[i] ? 1 : -1;
        for (size_t i = 0; i < indiv.gen().get_depth(); ++i)
                indiv.nn().step(inputs);
        ans_subproblem(inputs,xorand_res);

        //output.push_back(indiv.nn().get_graph()[v].get_current_output());
        //        // gsimp=indiv.nn().get_graph();
        //
        values=std::make_pair(xorand_res[t],indiv.nn().get_graph()[v].get_current_output());
        threshold.push_back(values);
        xorand_res.clear();
        //output.clear();
         }
        
        std::sort(threshold.begin(),threshold.end(),sort_pred);
        bool found=false;
        if (check_threshold(threshold))  // if there is a threshold..if t is solved by x
        {
         if (results.size()==0)
           {
                results.insert(std::make_pair(t,indiv.nn().get_graph()[v].get_id()));
                indiv.nn().get_graph()[v].set_solve(true,t);
           }
         else
           {
             for (it=results.begin();it!=results.end();it++)  
             {
               if (it->first==t)
                 {
                 found=true;
                  break;
                  }
            }
       if(!found)
         {
          results.insert(std::make_pair(t,indiv.nn().get_graph()[v].get_id()));
          indiv.nn().get_graph()[v].set_solve(true,t);
          }
        }
     }
//deb.open("/project/evolutionaryRobotics/hmengist/7.25/xorands/PCC100/debug.txt",std::fstream::out | std::fstream::app);
//deb<<"this is the size of threshold"<<threshold.size()<<" "<<t<<" "<<indiv.nn().get_graph()[v].get_id()<<endl;
   // for (int k=0;k<threshold.size();k++)
  // deb<<threshold.at(k).first<<" "<<threshold.at(k).second<<endl;
 //deb.close(); 
     threshold.clear();
     }
   }
 }
 cout<<"showing results:......"<<results.size()<<endl;
 std::fstream sol;
 for (it =results.begin();it!=results.end();++it)
    {
      cout<<it->first<<"  "<<it->second<<endl;
    }
    cout<<endl;
    sol.open("/project/evolutionaryRobotics/hmengist/7.25/allands/PCC25/solvent.txt",std::fstream::out | std::fstream::app);
    sol <<"nn"+_postFix<<" "<<results.size()/number_problems<<"\n";
    sol.close();
    std::ofstream ofs("/project/evolutionaryRobotics/hmengist/7.25/allands/PCC25/nn"+_postFix+".dot");
    indiv.nn().write(ofs);
}
bool check(std::vector<bool> v)
  {
        bool t =  v[0] ;
    for ( int i = 1; i < v.size(); i++ )
    {
        if (  v[i] != t )
          {
                return false;
          }
    }
 return true;
  }
bool check_threshold(std::vector<std::pair<bool,int>> thre)
{
        std::vector<bool> a;
        std::vector<bool> b;
        std::vector<bool> c;

for (int i=0;i<thre.size();i++)
  {
    if (thre.at(i).second == 1)
        a.push_back(thre.at(i).first);
    else if (thre.at(i).second == 0)
        b.push_back(thre.at(i).first);
    else if (thre.at(i).second == -1)
        c.push_back(thre.at(i).first);
  }
if (a.size()!=0)
   {
     if(!check(a))
        return false;
   }
if (b.size()!=0)
        {
       if(!check(b))
        return false;
        }
if (c.size()!=0)
        {
       if(!check(c))
        return false;
        }



if (a.size() >= b.size())
 {
   if (b.size() >= c.size())
     {
      if ((std::equal(b.begin(), b.end(), a.begin())) && (!std::equal(c.begin(), c.end(), b.begin())))
        return true;
     }
   else
     {
    if ((std::equal(b.begin(), b.end(), a.begin())) && (!std::equal(b.begin(), b.end(), c.begin())))
        return true;
     }

  }
else
 {
   if (b.size() >= c.size())
    {
     if ((std::equal(a.begin(), a.end(), b.begin())) && (!std::equal(c.begin(), c.end(), b.begin())))
        return true;
    }

 else
    {
    if ((std::equal(a.begin(), a.end(), b.begin())) && (!std::equal(b.begin(), b.end(), c.begin())))
      return true;
     }

  }


if (b.size() >= c.size())
 {
   if (c.size() >= a.size())
     {
       if ((std::equal(c.begin(), c.end(), b.begin())) && (!std::equal(a.begin(), a.end(), c.begin())))
        return true;
      }
    else
      {
        if ((std::equal(c.begin(), c.end(), b.begin())) && (!std::equal(c.begin(), c.end(), a.begin())))
          return true;
      }
  }

else
  {
    if (c.size() >= a.size())
     {
        if ((std::equal(b.begin(), b.end(), c.begin())) && (!std::equal(a.begin(), a.end(), c.begin())))
        return true;
     }
   else
       {
        if ((std::equal(b.begin(), b.end(), c.begin())) && (!std::equal(c.begin(), c.end(), a.begin())))
        return true;
       }
  }

return false;
}
    
template<typename I>
void currentoutput(I& indiv)
{
std::vector<int> output(indiv.nn().get_nb_neurons());
std::vector<string> name(indiv.nn().get_nb_neurons());

std::vector<float> inputs(8);
  for (size_t s = 0; s < 256; ++s) {
        std::bitset<8> in(s);
        for (size_t i = 0; i < in.size(); ++i)
               inputs[i] = in[i] ? 1 : -1;
        for (size_t i = 0; i < indiv.gen().get_depth(); ++i)
                indiv.nn().step(inputs);
        BGL_FORALL_VERTICES_T(v, indiv.nn().get_graph(), typename I::nn_t::graph_t) {
                output.push_back(indiv.nn().get_graph()[v].get_current_output());
                name.push_back(indiv.nn().get_graph()[v].get_id());


     }
 /*for (int k=0;k<output.size();k++)
 *         cout<<output.at(k)<<" ";*/
 cout<<output.at(8)<<" "<<output.at(9)<<" "<<output.at(10)<<" "<<output.at(11)<<" "<<output.at(12)<<" "<<output.at(13)<<" "<<output.at(14)<<" "<
 cout<<endl;
 /* for (int k=0;k<output.size();k++)
 *         cout<<name.at(k)<<" ";*/
 cout<<endl;
 //cout<<output.size()<<endl;
  output.clear();
    name.clear();
    cout<<endl;
    }
   }
 

};

long Params::seed = -1;
int main(int argc, char **argv)
{
  typedef FitXorXor<Params> fit_t;
  typedef phen::Parameters<gen::Sampled<1, Params::dnn::weight>,
                           fit::FitDummy<>, Params> weight_t;
  typedef phen::Parameters<gen::Sampled<1, Params::dnn::bias>,
                           fit::FitDummy<>, Params> bias_t;
  typedef PfWSum<weight_t> pf_t;
  typedef AfTanhNxor<bias_t> af_t;
  typedef sferes::gen::DnnSpatial<Neuron<pf_t, af_t>, Connection<weight_t>, Params> gen_t;
  typedef phen::Dnn<gen_t, fit_t, Params> phen_t;
  typedef eval::Parallel<Params> eval_t;
  typedef boost::fusion::vector
  <
     //  stat::ParetoFront<phen_t, Params>, // comment this line to remove pareto.dat
    stat::Mod<phen_t, Params>
  >  stat_t;

   // MVG cannot be used with DIV !
#if defined(DIV)and !defined(MVG)
  typedef modif::BehaviorDiv<> modifier_t;
#elif defined(MVG)
  typedef modif::Mvg<> modifier_t;
#elif defined(NOVMAP)
  typedef modif::Novmap<> modifier_t;
#else
  typedef modif::Dummy<> modifier_t;
#endif


#ifdef PNSGA
  typedef ea::Pnsga<phen_t, eval_t, stat_t, modifier_t, Params> ea_t;
#else
  typedef ea::Nsga2<phen_t, eval_t, stat_t, modifier_t, Params> ea_t;
#endif
  ea_t ea;

  if (argc > 1) // if a number is provided on the command line
  {
    int randomSeed = atoi(argv[1]);
    printf("randomSeed:%i\n", randomSeed);
    srand(randomSeed);  //set it as the random seed
    Params::seed = randomSeed;
    run_ea(argc, argv, ea, false);
  }
  else
  {
    run_ea(argc, argv, ea);
  }


  return 0;
}

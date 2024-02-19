#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Problem
{
    double epsilon;
    double x0; // initial point
    
    double f(double x)
    {
        return sin(x / 2) + cos(x / 4);
    }

    double df(double x)
    {
        return cos(x / 2) / 2 - sin(x / 4) / 4;
    }

    // solve the subproblem
    // argmin_x\in [xt-epsilon, xt+epsilon] f(x)
    double subproblem(double xt)
    {
     // TODO define hill-climbing subproblem
    }

public:
    Problem(double eps, double initial_guess)
    {
      // TODO initialise problem
    }

    void set_epsilon(double eps){
      // TODO method for setting epsilon  
    }

    void set_x0(double initial_guess){
        // TODO method for setting x0
    }


    // solve the problem using hill-climbing
    void solve()
    {
      // TODO implement hill-climbing
    }

};

int main()
{   
    // Solve problem with hill-climbing
    Problem p(0.5, -4);
    printf("hill climbing... \n");
    p.solve();

    // TODO your gradient ascent code
}


/* You should get
    Problem p(0.5, -4);
    printf("hill climbing... \n");
    p.solve();
    hill climbing... 
f(-3.5000) = -0.3430
f(-3.0000) = -0.2658
f(-2.5000) = -0.1380
f(-2.0000) = 0.0361
f(-1.5000) = 0.2489
f(-1.0000) = 0.4895
f(-0.5000) = 0.7448
f(-0.0050) = 0.9975
f(0.4900) = 1.2351
f(0.9850) = 1.4427
f(1.4850) = 1.6080
f(1.9850) = 1.7168
f(2.4850) = 1.7597
f(2.5400) = 1.7602
f(2.5400) = 1.7602
Maximum is at 2.540000 with value 1.760173 

    printf("\ngradient ascent... \n");
    p.GAsolve();
gradient ascent... 
f(-3.9989) = -0.3690
f(-3.9976) = -0.3690
f(-3.9962) = -0.3690
f(-3.9947) = -0.3690
f(-3.9930) = -0.3690
f(-3.9912) = -0.3690
f(-3.9892) = -0.3690
f(-3.9870) = -0.3689
f(-3.9846) = -0.3689
f(-3.9820) = -0.3689
f(-3.9791) = -0.3689
f(-3.9759) = -0.3689
f(-3.9724) = -0.3689
f(-3.9686) = -0.3688
f(-3.9644) = -0.3688
f(-3.9598) = -0.3687
f(-3.9548) = -0.3687
f(-3.9492) = -0.3686
f(-3.9431) = -0.3686
f(-3.9365) = -0.3685
f(-3.9291) = -0.3683
f(-3.9211) = -0.3682
f(-3.9122) = -0.3680
f(-3.9025) = -0.3678
f(-3.8918) = -0.3676
f(-3.8801) = -0.3673
f(-3.8672) = -0.3670
f(-3.8531) = -0.3665
f(-3.8375) = -0.3660
f(-3.8204) = -0.3654
f(-3.8016) = -0.3647
f(-3.7809) = -0.3638
f(-3.7581) = -0.3627
f(-3.7331) = -0.3614
f(-3.7055) = -0.3598
f(-3.6751) = -0.3578
f(-3.6417) = -0.3555
f(-3.6048) = -0.3526
f(-3.5642) = -0.3492
f(-3.5194) = -0.3449
f(-3.4700) = -0.3398
f(-3.4156) = -0.3336
f(-3.3555) = -0.3260
f(-3.2892) = -0.3167
f(-3.2160) = -0.3055
f(-3.1353) = -0.2918
f(-3.0463) = -0.2751
f(-2.9481) = -0.2549
f(-2.8399) = -0.2303
f(-2.7209) = -0.2005
f(-2.5901) = -0.1646
f(-2.4466) = -0.1215
f(-2.2897) = -0.0701
f(-2.1187) = -0.0091
f(-1.9332) = 0.0625
f(-1.7330) = 0.1455
f(-1.5187) = 0.2403
f(-1.2910) = 0.3468
f(-1.0517) = 0.4637
f(-0.8030) = 0.5891
f(-0.5479) = 0.7201
f(-0.2902) = 0.8528
f(-0.0338) = 0.9831
f(0.2173) = 1.1069
f(0.4590) = 1.2209
f(0.6881) = 1.3226
f(0.9021) = 1.4106
f(1.0991) = 1.4848
f(1.2784) = 1.5459
f(1.4398) = 1.5952
f(1.5837) = 1.6343
f(1.7111) = 1.6648
f(1.8232) = 1.6884
f(1.9213) = 1.7064
f(2.0068) = 1.7201
f(2.0811) = 1.7304
f(2.1454) = 1.7381
f(2.2009) = 1.7438
f(2.2489) = 1.7481
f(2.2901) = 1.7513
f(2.3257) = 1.7536
f(2.3562) = 1.7553
f(2.3824) = 1.7566
f(2.4049) = 1.7576
f(2.4242) = 1.7583
f(2.4408) = 1.7588
f(2.4550) = 1.7591
f(2.4671) = 1.7594
f(2.4776) = 1.7596
f(2.4865) = 1.7598
f(2.4941) = 1.7599
f(2.5007) = 1.7600
f(2.5063) = 1.7600
f(2.5110) = 1.7601
f(2.5152) = 1.7601
f(2.5187) = 1.7601
f(2.5217) = 1.7601
f(2.5242) = 1.7601
f(2.5264) = 1.7601
f(2.5283) = 1.7602
f(2.5299) = 1.7602
f(2.5313) = 1.7602
f(2.5325) = 1.7602
f(2.5335) = 1.7602
f(2.5344) = 1.7602
f(2.5351) = 1.7602
f(2.5357) = 1.7602
f(2.5363) = 1.7602
f(2.5367) = 1.7602
f(2.5371) = 1.7602
f(2.5375) = 1.7602
f(2.5378) = 1.7602
f(2.5380) = 1.7602
f(2.5382) = 1.7602
f(2.5384) = 1.7602
f(2.5385) = 1.7602
f(2.5387) = 1.7602
f(2.5388) = 1.7602
f(2.5389) = 1.7602
f(2.5390) = 1.7602
f(2.5390) = 1.7602
f(2.5391) = 1.7602
f(2.5392) = 1.7602
f(2.5392) = 1.7602
f(2.5392) = 1.7602
f(2.5393) = 1.7602
f(2.5393) = 1.7602
f(2.5393) = 1.7602
f(2.5393) = 1.7602
f(2.5394) = 1.7602
f(2.5394) = 1.7602
f(2.5394) = 1.7602
f(2.5394) = 1.7602
f(2.5394) = 1.7602
Maximum is at 2.539412 with value 1.760173

*/
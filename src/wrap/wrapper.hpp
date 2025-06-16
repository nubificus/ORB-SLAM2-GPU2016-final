#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudafeatures2d.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/cudaarithm.hpp>
#include <ORBextractor.h>
#include <cuda/Allocator.hpp>
#include <cuda/Fast.hpp>
#include <cuda/Orb.hpp>
#include <Utils.hpp>

#include <vaccel.h>

#include "utils.hpp"
#include "../include/ORBextractor.h"
#include "../include/Frame.h"



extern "C" __attribute__((visibility("default")))

void my_wrapped_orb_operator(struct vaccel_arg *read, size_t nr_read,
		  struct vaccel_arg *write, size_t nr_write);
// {

//     cv::Mat image;
//     deserialize_mat(read[0].buf,read[0].size,image);

//     cv::Mat mask;
//     deserialize_mat(read[1].buf,read[1].size,mask);

//     std::vector<KeyPoint> keypoints;
// 	deserialize_vec_of_keypoints(read[2].buf,read[2].size,keypoints);

//     int nFeatures=2000;

//     float fScaleFactor= 1.2;

//     int nLevels =8;

//     int fIniThFAST=20;

//     int fMinThFAST=7;

//     cv::Mat descriptors;
    
//     ORB_SLAM2::ORBextractor* mpORBextractor = new ORB_SLAM2::ORBextractor(nFeatures,fScaleFactor,nLevels,fIniThFAST,fMinThFAST);

//     // mpORBextractorLeft->operator()(im, cv::Mat(), mvKeys, mDescriptors);
//     (*mpORBextractor)(image,mask,keypoints,descriptors);

//     size_t descriptors_size;
//     serialize_mat_new(descriptors, write[0].buf, descriptors_size);
//     write[0].size = descriptors_size;
// }






// #include <vector>
// #include <opencv2/core.hpp>
// #include <opencv2/core/core.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/core/cuda.hpp>
// #include <opencv2/cudafeatures2d.hpp>
// #include <opencv2/cudawarping.hpp>
// #include <opencv2/cudaarithm.hpp>
// #include <ORBextractor.h>
// #include <cuda/Allocator.hpp>
// #include <cuda/Fast.hpp>
// #include <cuda/Orb.hpp>
// #include <Utils.hpp>

// #include <vaccel.h>

// #include "utils.hpp"
// #include "../include/ORBextractor.h"


// extern "C" {

// void my_wrapped_orb_operator(struct vaccel_arg *read, size_t nr_read,
// 		  struct vaccel_arg *write, size_t nr_write);

// }
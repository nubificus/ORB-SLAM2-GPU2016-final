    #include "wrapper.hpp"


    extern "C" {

    void my_wrapped_orb_operator(struct vaccel_arg *read, size_t nr_read,
            struct vaccel_arg *write, size_t nr_write)
    {

        cv::Mat image;
        deserialize_mat(read[0].buf,read[0].size,image);

        cv::Mat mask;
        deserialize_mat(read[1].buf,read[1].size,mask);

        std::vector<KeyPoint> keypoints;
        // deserialize_vec_of_keypoints(read[2].buf,read[2].size,keypoints);

        cv::Mat descriptors;
        // deserialize_mat(read[3].buf,read[3].size,descriptors);

        int nFeatures=2000;

        float fScaleFactor= 1.2;

        int nLevels =8;

        int fIniThFAST=20;

        int fMinThFAST=7;

        ORB_SLAM2::ORBextractor* mpORBextractor = new ORB_SLAM2::ORBextractor(nFeatures,fScaleFactor,nLevels,fIniThFAST,fMinThFAST);

        // mpORBextractorLeft->operator()(im, cv::Mat(), mvKeys, mDescriptors);
        (*mpORBextractor)(image,mask,keypoints,descriptors);

        size_t keypoints_size;
        write[0].buf = serialize_vec_of_keypoints_new(keypoints, write[0].buf, keypoints_size);
        write[0].size = keypoints_size;

        size_t descriptors_size;
        write[1].buf = serialize_mat_new(descriptors, write[1].buf, descriptors_size);
        write[1].size = descriptors_size;


    }


    }

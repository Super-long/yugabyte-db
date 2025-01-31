// Copyright (c) YugaByte, Inc.

import { connect } from 'react-redux';
import { toast } from 'react-toastify';
import { UpdateRelease } from '../../../components/releases';
import {
  deleteYugaByteRelease,
  getYugaByteReleases,
  getYugaByteReleasesResponse,
  updateYugaByteRelease,
  updateYugaByteReleaseResponse
} from '../../../actions/customers';
import { createErrorMessage } from '../../alerts/AlertConfiguration/AlertUtils';

const mapDispatchToProps = (dispatch) => {
  return {
    updateYugaByteRelease: (version, payload) => {
      dispatch(updateYugaByteRelease(version, payload)).then((response) => {
        dispatch(updateYugaByteReleaseResponse(response.payload));
      });
    },
    deleteYugaByteRelease: (version) => {
      dispatch(deleteYugaByteRelease(version)).then((response) => {
        if (response.error) toast.error(createErrorMessage(response.payload));
        else
          dispatch(getYugaByteReleases()).then((response) => {
            dispatch(getYugaByteReleasesResponse(response.payload));
          });
      });
    }
  };
};

function mapStateToProps(state) {
  return {
    updateRelease: state.customer.updateRelease
  };
}

export default connect(mapStateToProps, mapDispatchToProps)(UpdateRelease);
